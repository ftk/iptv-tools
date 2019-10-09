#!/usr/bin/perl -CSDA
# Downloads and prints channel list from acestream.
# Requires acestream proxy to be available (replace ip and port below)
#
use strict;
use warnings;
use v5.22;
use JSON;
use LWP::Simple;

my $channels = from_json(get('http://search.acestream.net/all?api_version=1.0&api_key=test_api_key'));

for my $ch (@{$channels}) {
    next if $ch->{'availability'} < 0.85 || 
        $ch->{'availability_updated_at'} < time() - 24 * 60 * 60;

    say join "\t", 
        $ch->{'name'},
        "http://192.168.2.111:8000/infohash/$ch->{'infohash'}/stream.mp4",
        $ch->{'categories'}->[0] // 'other',
        '';
}
