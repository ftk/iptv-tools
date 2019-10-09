iptv-tools is a collection of perl and bash scripts for IPTV.

* XMLTV parser (parser-xmltv.pl)
Parses xmltv and puts in sqlite database for efficient retrieval of current TV programme.

* M3U parser (m3u.pl)
Converts m3u to tab-separated values (tsv-file).

* DLNA/UPNP Controller (upnp.sh)
Uses curl to control DLNA/UPNP renderer.
Example: stop playback, then set name and uri of stream, then play it
./upnp.sh stop name "Test stream" uri "http://example.org/stream.mp4" play

* CGI script for generating HTML list of TV channels with TV guide info (index.pl)

* Simple CGI wrapper to cast a stream to DLNA from your LAN
Example: start: socat TCP-LISTEN:8081,fork,reuseaddr EXEC:./caster.sh,stderr &
cast stream to DLNA: curl http://localhost:8081/cast/http://example.org/stream.mp4

* TV control using keyboard (controller.sh)
You need:
- (wireless) keyboard
- script running
- DLNA device
- (IPTV) playlist
You can:
- remote control your DLNA for playing streams from playlist using keyboard
- select random stream
- search for stream using keyboard
- adjust volume (kp plus, kp minus)

* Script for getting live streams from AceStream broadcasting engine (acesearch.pl)
More info about acestream at:
http://acestream.org/
http://wiki.acestream.org/wiki/index.php/Download
https://github.com/pepsik-kiev/HTTPAceProxy (HTTP proxy - optional)

Dependencies:
For perl scripts:
apt-get install libxml-twig-perl libutf8-all-perl libtimedate-perl libdbd-sqlite3-perl libdbi-perl libcgi-pm-perl libtext-charwidth-perl libtext-iconv-perl libtext-wrapi18n-perl libjson-perl
For bash scripts:
apt-get install gawk bash curl socat
For gssdp-discover (if your DLNA device changes port/address)
apt-get install gupnp-tools
