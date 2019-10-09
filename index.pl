#!/usr/bin/perl -CSDA
# Display playlist with TV guide in browser via HTML
# Features:
# DLNA casting by clicking on channel icon
# Table sorting (javascript)
# Show programme description by clicking on its name (javascript)
# Filter by channel category (faster rendering on mobile devices for large playlists) (add ?c=Category to request)
# Requires Perl::CGI

# Configuration:
my $playlist_file = defined(param('as')) ? "/root/pls/iptv-as.txt" : defined(param('ar')) ? "/root/pls/iptv-ar.txt" :  defined(param('ace')) ? "/root/pls/iptv-ace.txt" : "/root/pls/iptv-nb.txt"; # TSV playlist (see m3u.pl)
my $tvguide_file = "/root/pls/tvg"; # TV Guide sqlite file (see parse-xmltv.pl)

my $now = int(param('time') // time()); # unix time for programme

my $caster = param('caster') // 'http://192.168.2.111:8081/cast/'; # caster url
my $category = param('c');

use strict;
use v5.22;
use CGI  qw/:standard /;
use utf8;

sub normalize {
    $_ = shift;
    s/\s+//g; # remove spaces
    s/-//g; # remove dashes
    s/HD$//; # remove HD suffix
    return lc($_); # lower case
}

charset('utf-8');
print header;

use DBI;
my $dbh = DBI->connect("dbi:SQLite:dbname=${tvguide_file}","","", {RaiseError=>1, ReadOnly => 1, sqlite_unicode=>1}) or die("db disconnected");
my $curpr = $dbh->prepare("select title, category, description, (100 * ($now - start) / (stop - start))
                          from programmes where channel=? and start <= $now and stop >= $now limit 1");
my $nextpr = $dbh->prepare("select title, category, description, (start - $now) / 60
                           from programmes where channel=? and start >= $now order by start asc limit 1");

use POSIX qw(strftime);
print start_html(-title=>strftime("%T %F", localtime($now))); # print time in title

# CSS
say qq{<style>
details {
  display:inline-block;
}

table {
 table-layout: fixed;
 width: 100%;
 border-collapse: collapse;
 border: 1px solid black;
 overflow-wrap: break-word;
}

img {
  width: 100%;
  height: 100%;
}

};
# column widths, in percents
my @len = ( 3, 14, 20, 3, 30, 30 );

for my $i (0...@len-1) {
    my $j = $i + 1;
    say qq[
th:nth-child($j) {
  width: $len[$i]%;
}
];
}
say "</style>";

open my $playlist, "<", $playlist_file or die $!;

say qq{<table border="1">};
say qq{<tr><th></th>};
say qq{<th>Group</th>};
say qq{<th>Name</th><th>%</th><th>Programme</th><th>Next</th></tr>};

# iterate channels
while ( <$playlist> ) {
    chomp;
    my @p = split /\t/;
    my $ch = $p[0];
    if (!defined($category) || $category eq $p[2]) {

        say qq{<tr><td><a href="${caster}${p[1]}" target="_blank" class="caster">};
        if (length $p[3]) {
            say qq{<img src="${p[3]}" /></a></td>};
        } else {
            say qq{C</a></td>};
        }

        my ($title, $cat, $desc, $percentage);
        $curpr->execute(normalize($ch));
        $curpr->bind_columns(\$title, \$cat, \$desc, \$percentage);

        my $ok = $curpr->fetch;
        my $doubt = "";
        if(!$ok) {
            # try channel name without brackets
            $ch =~ s/\(.+\)//g;
            $curpr->execute(normalize($ch));
            $ok = $curpr->fetch;
            $doubt = "?";
        }

        my $cat2 = $cat // $category;
        $cat2 = $p[2] unless length($cat2) > 3;
        say qq{<td>$cat2</td>};# if !defined($category);
        say qq{<td><a href="${p[1]}" type="video/mp2t">$ch</a></td>};

        if($ok) {
            if (defined($desc)) {
                say qq{<td>${percentage}${doubt}</td><td><details><summary>$title</summary><tt>$desc</tt></details>$cat</td>};
            } else {
                say qq{<td>${percentage}${doubt}</td><td>$title $cat</td>};
            }
        } else {
            say qq{<td></td><td></td>};
        }
        
        $nextpr->execute(normalize($ch));
        my $timetonext;
        $nextpr->bind_columns(\$title, \$cat, \$desc, \$timetonext);
        if($nextpr->fetch) {
            if (defined($desc)) {
                say qq{<td>(→${timetonext}) <details><summary>$title</summary><tt>$desc</tt></details>$cat</td>};
            } else {
                say qq{<td>(→${timetonext}) $title $cat</td>};
            }
        } else {
            say qq{<td></td>};
        }
        say qq{</tr>};
    }
}

say qq{</table>};

# append javascript
say q%<script>
const getCellValue = (tr, idx) => tr.children[idx].innerText || tr.children[idx].textContent;

const comparer = (idx, asc) => (a, b) => ((v1, v2) => 
        /*v1 == '' ? 1 : v2 == ''  ? -1 :*/ v1 !== '' && v2 !== '' && !isNaN(v1) && !isNaN(v2) ? v1 - v2 : v1.toString().localeCompare(v2)
        )(getCellValue(asc ? a : b, idx), getCellValue(asc ? b : a, idx));


function cast(e) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', this.href, true);
    xhr.send();
    return false;
}

window.onload = function () {
    document.querySelectorAll(".caster").forEach(function(e){
        e.onclick = cast;
    });

document.querySelectorAll('th').forEach(th => th.addEventListener('click', (() => {
    const table = th.closest('table');
Array.from(table.querySelectorAll('tr:nth-child(n+2)'))
    .sort(comparer(Array.from(th.parentNode.children).indexOf(th), this.asc = !this.asc))
    .forEach(tr => table.appendChild(tr) );
})));

}

</script>
%;

print end_html;
