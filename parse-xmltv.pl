#!/usr/bin/perl -CSDA
# parses xmltv file into sqlite database, extracts tv channel name and programme names, start & stop times (converts to unix timestamps) and category & description if available

# if a sqlite db exists, script adds new programmes to it
# if channel filter is specified, it will add only programme for channels from the list (first column of tsv)
# the script will remove expired tv guide info from db

# usage: perl parse-xmltv.pl xmltv.xml tvg.sqlite (channel-filter.tsv)

use strict;
use warnings;
use v5.22;


use utf8::all;


my $now = time();
my $xmltv = $ARGV[0] // 'ttv.xmltv.xml';
my $db = $ARGV[1] // "tvg";
my $filter_filename = $ARGV[2];

my $past_progs = 60 * 60;

sub normalize {
    $_ = shift;
    s/\s+//g; # remove spaces
    s/-//g; # remove dashes
    s/HD$//; # remove HD suffix
    return lc($_); # lower case
}

use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=${db}","","", {RaiseError=>1, sqlite_journal_mode => 'WAL', sqlite_unicode=>1}) or die("db disconnected");

$dbh->{AutoCommit} = 0;
$dbh->do('CREATE TABLE IF NOT EXISTS programmes 
         (channel TEXT NOT NULL, title TEXT, start INTEGER NOT NULL, stop INTEGER NOT NULL, category TEXT, description TEXT ,
         UNIQUE (channel, start) ON CONFLICT REPLACE
         )');
$dbh->do('CREATE INDEX IF NOT EXISTS prog_search ON programmes (channel, start)');

my $sth = $dbh->prepare('INSERT OR REPLACE INTO programmes (channel, title, start, stop, category, description) VALUES (?,?,?,?,?,?)');

use DateTime;
sub get_dt {
    my $d = shift;
    DateTime->new(
        year => substr($d,0,4),
        month => substr($d,4,2),
        day => substr($d,6,2),
        hour => substr($d,8,2),
        minute => substr($d,10,2),
        second => substr($d,12,2),
        time_zone => substr($d,15),
        );

}


my %channels = ();

my %filter;
my $filter_enabled = 0;
if (defined($filter_filename) && open(my $fh, "<", $filter_filename)) {
    for (<$fh>) {
        my @p = split /\t/;
        my $ch = $p[0]; # first column
        #$filter{$ch} = 1;
        $filter{normalize($ch)} = 1;
    }
    $filter_enabled = 1;
}

$dbh->do("DELETE FROM programmes WHERE stop < $now - $past_progs");

use XML::Twig;
XML::Twig->new(twig_handlers => 
               { 
                   # assume <channel> tags are always before <programme>
                   'tv/channel' => sub { 
                       my( $t, $_) = @_;

                       my $id = $_->{att}->{id};
                       #my $name = $_->first_child('display-name')->text;
                       # TODO: one channel id may refer to multiple channel names
                       #say "$id: $channels{$id} -> $name" if exists($channels{$id});
                       for my $n ($_->children('display-name')) {
                           next if ($filter_enabled && !defined($filter{normalize($n->text)}));
                           $channels{$id} = normalize($n->text);
                       }
                       $t->purge;
                   },
                       'tv/programme' => sub {
                           my( $t, $_) = @_;
                           my $ch = $channels{$_->{att}->{channel}};
                           
                           if (!defined($ch)) {
                               return;
                           }

                           #my $ref = $prog{$_->{att}->{channel}};
                           my $start = get_dt $_->{att}->{start};
                           my $stop = get_dt $_->{att}->{stop};

                           return if($stop->epoch < $now - $past_progs);
                           
                           
                           my $title = $_->first_child('title')->text;
                           
                           $sth->execute($ch, 
                                         $title, 
                                         $start->epoch, 
                                         $stop->epoch, 
                                         $_->first_child('category') ? $_->first_child('category')->text : undef, 
                                         $_->first_child('desc') ? $_->first_child('desc')->text : undef
                               );
                           $t->purge;
                   }
               }
    )
    ->parsefile($xmltv);


$dbh->commit;

#$dbh->{AutoCommit} = 1;
#$dbh->do("VACUUM");
