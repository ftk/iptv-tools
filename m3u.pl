#!/usr/bin/perl
# This script parses M3U into tab-separated values (tsv-file)
# Only supports entries with EXTINF tag

# EXTM3U is hard to parse and use from shell scripts
# I couldnt find a working M3U parser so I wrote my own

# Examples:

# cat playlist.m3u | ./m3u.pl | cut -d '\t' -f 3 | sort -u 
# gets all groups(categories) from playlist

# ./m3u.pl playlist.m3u | awk -F'\t' '$1 == "My item" {print $2}' 
# prints URL of My item

use Text::ParseWords;
use strict;
use warnings;
use v5.22;
use utf8::all;


while ( <> ) {
    # m3u parser
    # populate opts hash-array

    chomp;
    next unless /^#EXTINF:/;
    my @p = split /,/;

    my @args = shellwords($p[0]);

    my %opts = ();
    $opts{time} = shift @args;
    $opts{time} =~ s/^#EXTINF://;

    $opts{name} = $p[1];
    
    my $url = <>;
    chomp $url;
    $opts{url} = $url;
    
    
    for my $a ( @args ) {
        my @kv = split /=/, $a, 2;
        $opts{$kv[0]} = $kv[1];
    }
    # m3u parsed!

    # remove junk from channel name
    $opts{name} =~ s/\Q (на модерации)\E$//;

    # print channels as tab separated values (tsv-file)
    # you can modify to add your fields
    say join("\t",
             $opts{name},
             $opts{url},
             $opts{'group-title'},
             $opts{'tvg-logo'}
        );
}
