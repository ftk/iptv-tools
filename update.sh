#!/bin/bash
# Generates playlist and updates tv guide

hostname=192.168.2.111

# acestream playlist from pomoyka
curl  --fail --compressed -R http://pomoyka.win/trash/ttv-list/as.all.tag.player.m3u | sed "s%^acestream://%http://${hostname}:6878/ace/getstream?id=%"  > iptv-as.m3u 

cat iptv-as.m3u | perl m3u.pl|  awk -F'\t' '{OFS="\t";print $1, $2, $3, ""}' > iptv-as.txt
cat iptv-as.txt > tv-comb.txt

# acestream playlist from acesearch
perl -CSDA acesearch.pl > iptv-nb.txt
cat iptv-nb.txt >> tv-comb.txt

# acestream playlist from httpaceproxy
curl -o iptv-ace.m3u http://${hostname}:8000/torrent-telik

cat iptv-ace.m3u | perl m3u.pl > iptv-ace.txt
cat iptv-ace.txt >> tv-comb.txt


# update tv guide sqlite database
rm /tmp/tvg
#set -e
cp tvg /tmp/
for url in 'http://tv.k210.org/xmltv.xml.gz' 'http://programtv.ru/xmltv.xml.gz' 'https://iptvx.one/epg/epg.xml.gz' 'http://www.teleguide.info/download/new3/xmltv.xml.gz'
do
    echo $url
    curl -kL "$url" | gunzip > /tmp/xmltv.xml && ./parse-xmltv.pl /tmp/xmltv.xml /tmp/tvg tv-comb.txt
    rm /tmp/xmltv.xml
done

mv /tmp/tvg .
