#!/usr/bin/perl
# Simple script to get current programme from sqlite db

my $now = time();

my $db = "tvg"; # sqlite file

use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=$db","","", {RaiseError=>1, sqlite_journal_mode => 'WAL', ReadOnly   => 1}) or die("db disconnected");
my $curpr = $dbh->prepare("select channel, title, category, description , (100 * ($now - start) / (stop - start))
                          from programmes where channel = ? and start <= $now and stop >= $now 
                          limit 1");

my $ch = $ARGV[0]; # channel name
#print $ch;
$curpr->execute(${ch});

my ($title, $cat, $desc, $percentage);
$curpr->bind_columns(\$ch, \$title, \$cat, \$desc, \$percentage);

while ($curpr->fetch) {
    print "${title}\t${percentage}\t${cat}\t${desc}\n";
}
