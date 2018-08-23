#!/bin/bash
# Example usage: upnp.sh stop name "Visible name" uri "http://example.org/example.mp4" play
# Will stop playback, set URI and then play it

# Setting up:
# We need upnp avtransport control url to control our dlna device
# If your dlna client has static IP and port you can remove the next part and set control url directly

# My LG TV changes the DLNA port at every launch and the only way to get the port number is via SSDP discover protocol


# gssdp-discover -i wlan0 --timeout=3
# will return a list of all DLNA devices that respond

# we will cache the port to enable faster operation
cached=0
[ -r /tmp/upnpavtransport ] && device="$(cat /tmp/upnpavtransport)" && cached=1

# now lets parse and filter results to LG TV
[ -z "$device" ] && device="$(gssdp-discover -n 3 | grep -A1 'AVTransport' | sed -n 's/^ *Location: *//p' | grep '\.112:' | head -n 1)"
[ -z "$device" ] && echo Cant find device! >&2 && exit 1
echo $device > /tmp/upnpavtransport

# Set AVTransport control URL here
# you can see it at http://deviceaddr:port/
url="${device}AVTransport/d001bcab-5abf-c837-9d2a-66ea14ef20ff/control.xml"

# for volume control, set RenderingControl also
urlrender="${device}RenderingControl/d001bcab-5abf-c837-9d2a-66ea14ef20ff/control.xml"

while [ "$#" -gt 0 ]
do
if [ "$1" = "stop" ]
then

     cat <<EOF | curl --max-time 2 -K -
url = "$url"
header = "Content-Type: text/xml; charset=utf-8"
header = "SOAPAction: \"urn:schemas-upnp-org:service:AVTransport:1#Stop\""
data = "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:Stop xmlns:u=\"urn:schemas-upnp-org:service:AVTransport:1\"><InstanceID>0</InstanceID></u:Stop></s:Body></s:Envelope>"
silent

EOF
     # update cached address
     if [ "$?" -ne 0 -a "$cached" -eq 1 ]
     then
          rm /tmp/upnpavtransport
          exec "$0" "$@"
     fi
     shift
elif [ "$1" = "play" ]
then
     cat <<EOF | curl --max-time 2 -K - 
url = "$url"
header = "Content-Type: text/xml; charset=utf-8"
header = "SOAPAction: \"urn:schemas-upnp-org:service:AVTransport:1#Play\""
data = "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:Play xmlns:u=\"urn:schemas-upnp-org:service:AVTransport:1\"><InstanceID>0</InstanceID><Speed>1</Speed></u:Play></s:Body></s:Envelope>"
silent

EOF
     shift
elif [ "$1" = "uri" ]
then
     type='video/mp4'
     [ -z "$name" ] && name="$2"
     cat <<EOF | curl --max-time 3 -K - 
url = "$url"
header = "Content-Type: text/xml; charset=utf-8"
header = "Contentfeatures.dlna.org: DLNA.ORG_OP=01;DLNA.ORG_CI=0;DLNA.ORG_FLAGS=01700000000000000000000000000000"
header = "TransferMode.dlna.org: Streaming"
header = "SOAPAction: \"urn:schemas-upnp-org:service:AVTransport:1#SetAVTransportURI\""
data = "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:SetAVTransportURI xmlns:u=\"urn:schemas-upnp-org:service:AVTransport:1\"><InstanceID>0</InstanceID><CurrentURI>${2}</CurrentURI><CurrentURIMetaData>&lt;DIDL-Lite xmlns=\"urn:schemas-upnp-org:metadata-1-0/DIDL-Lite/\" xmlns:upnp=\"urn:schemas-upnp-org:metadata-1-0/upnp/\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:dlna=\"urn:schemas-dlna-org:metadata-1-0/\" xmlns:sec=\"http://www.sec.co.kr/\"&gt;&lt;item id=\"1\" parentID=\"parent\" restricted=\"1\"&gt;&lt;upnp:class&gt;object.item.videoItem&lt;/upnp:class&gt;&lt;dc:title&gt;${name}&lt;/dc:title&gt;&lt;dc:creator&gt;Unknown Artist&lt;/dc:creator&gt;&lt;upnp:artist&gt;Unknown Artist&lt;/upnp:artist&gt;&lt;upnp:album&gt;Unknown Album&lt;/upnp:album&gt;&lt;res protocolInfo=\"http-get:*:${type}:DLNA.ORG_OP=01;DLNA.ORG_FLAGS=01700000000000000000000000000000\"&gt;${2}&lt;/res&gt;&lt;/item&gt;&lt;/DIDL-Lite&gt;</CurrentURIMetaData></u:SetAVTransportURI></s:Body></s:Envelope>"
silent

EOF

     shift 2
elif [ "$1" = "get" ]
then 
    cat <<EOF | curl -K -
url = "$url"
header = "Content-Type: text/xml; charset=utf-8"
header = "SOAPAction: \"urn:schemas-upnp-org:service:AVTransport:1#GetTransportInfo\""
data = "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:GetTransportInfo xmlns:u=\"urn:schemas-upnp-org:service:AVTransport:1\"><InstanceID>0</InstanceID></u:GetTransportInfo></s:Body></s:Envelope>"
max-time = 5
silent

EOF
    shift
elif [ "$1" = "name" ]
then
     name="$2"
     shift 2
elif [ "$1" = "getvol" ]
then
     cat <<EOF | curl --max-time 3 -K - | sed -n 's%^.*<CurrentVolume>\(.*\)</CurrentVolume>.*$%\1%p'
url = "$urlrender"
header = "Content-Type: text/xml; charset=utf-8"
header = "SOAPAction: \"urn:schemas-upnp-org:service:RenderingControl:1#GetVolume\""
data = "<?xml version=\"1.0\"?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:GetVolume xmlns:u=\"urn:schemas-upnp-org:service:RenderingControl:1\"><Channel>Master</Channel><InstanceID>0</InstanceID></u:GetVolume></s:Body></s:Envelope>"
silent
EOF
     
     shift 1
elif [ "$1" = "setvol" ]
then
     cat <<EOF | curl --max-time 3 -K - | sed -n 's%^.*<CurrentVolume>\(.*\)</CurrentVolume>.*$%\1%p'
url = "$urlrender"
header = "Content-Type: text/xml; charset=utf-8"
header = "SOAPAction: \"urn:schemas-upnp-org:service:RenderingControl:1#SetVolume\""
data = "<?xml version=\"1.0\"?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:SetVolume xmlns:u=\"urn:schemas-upnp-org:service:RenderingControl:1\"><DesiredVolume>${2}</DesiredVolume><Channel>Master</Channel><InstanceID>0</InstanceID></u:SetVolume></s:Body></s:Envelope>"
silent
EOF
     shift 2
elif [ "$1" = "volup" ]
then
     vol=$("$0" getvol)
     exec "$0" setvol $((vol+1))
elif [ "$1" = "voldown" ]
then
     vol=$("$0" getvol)
     exec "$0" setvol $((vol-1))
else
    echo Usage: $0 uri [uri]
    echo Usage: $0 play
    echo Usage: $0 stop
    shift
fi
     
done
