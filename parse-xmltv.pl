# parses xmltv file into sqlite database, extracts tv channel name and programme names, start & stop times (converts to unix timestamps) and category & description if available

# if a sqlite db exists, script adds new programmes to it
# if channel filter is specified, it will add only programme for channels from the list (first column of tsv)
# the script will remove expired tv guide info from db

# usage: perl parse-xmltv.pl xmltv.xml tvg.sqlite (channel-filter.tsv)

use warnings;
use v5.22;


use utf8::all;



my $now = time();
my $xmltv = $ARGV[0] // 'ttv.xmltv.xml';
my $db = $ARGV[1] // "tvg";

use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=${db}","","", {RaiseError=>1, sqlite_journal_mode => 'WAL'}) or die("db disconnected");

$dbh->{AutoCommit} = 0;
$dbh->prepare('CREATE TABLE IF NOT EXISTS programmes 
              (channel TEXT NOT NULL, title TEXT, start INTEGER NOT NULL, stop INTEGER NOT NULL, category TEXT, description TEXT ,
              UNIQUE (channel, start) ON CONFLICT REPLACE
              )')->execute();
$dbh->prepare('CREATE INDEX IF NOT EXISTS prog_search ON programmes (channel, start)')->execute();

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
if (defined($ARGV[2]) && open(my $fh, "<", $ARGV[2])) {
    for (<$fh>) {
        my @p = split /\t/;
        my $ch = $p[0]; # first column
        $filter{$ch} = 1;
    }
    $filter_enabled = 1;
}

$dbh->do("DELETE FROM programmes WHERE stop < $now");

use XML::Twig;
XML::Twig->new( twig_handlers => 
                { 
                    # assume <channel> tags are always before <programme>
                    'tv/channel' => sub { 
                        my $id = $_->{att}->{id};
                        my $name = $_->first_child('display-name')->text;
                        # TODO: one channel id may refer to multiple channel names
                        say "$id: $channels{$id} -> $name" if exists($channels{$id});
                        $channels{$id} = $name;
                    },
                        'tv/programme' => sub {
                            my $ch = $channels{$_->{att}->{channel}};
                            
                            if (!defined($ch)) {
                                say "Channel " . $_->{att}->{channel} . " is not defined in XMLTV";
                                return;
                            }
                            return if ($filter_enabled && defined($filter{$ch}));

                            #my $ref = $prog{$_->{att}->{channel}};
                            my $start = get_dt $_->{att}->{start};
                            my $stop = get_dt $_->{att}->{stop};

                            return if($stop->epoch < $now);
                            
                            
                            my $title = $_->first_child('title')->text;
                            
                            $sth->execute($ch, 
                                          $title, 
                                          $start->epoch, 
                                          $stop->epoch, 
                                          $_->first_child('category') ? $_->first_child('category')->text : undef, 
                                          $_->first_child('desc') ? $_->first_child('desc')->text : undef
                                );
                    }
                },
                #output_encoding => 'UTF-8',
    )
    ->parsefile($xmltv);


$dbh->commit;

$dbh->{AutoCommit} = 1;
$dbh->do("VACUUM");
