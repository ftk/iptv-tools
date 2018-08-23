#!/bin/bash

# Simple CGI script for casting DLNA content

# Usage: socat TCP-LISTEN:8081,fork,reuseaddr EXEC:./caster.sh,stderr &
# then curl http://localhost:8081/cast/http://example.org/stream.mp4

# Should only be used in local network

# See upnp.sh for configuration

read request

while /bin/true; do
  read header
  [ "$header" == $'\r' ] && break;
done


if [[ "$request" =~ ^GET\ \/cast\/(.*)\ HTTP\/.*$ ]]
then

url="${BASH_REMATCH[1]}"

echo -e "HTTP/1.1 200 OK\r"
echo -e "Content-Type: text/plain\r"
echo -e "Access-Control-Allow-Origin: *\r" # allow ajax requests
echo -e "\r"
exec ./upnp.sh stop uri "$url" play 2>&1
exit 0

else
echo -e "HTTP/1.1 404 Not Found\r"
echo -e "Access-Control-Allow-Origin: *\r"
echo -e "\r"
echo 404

exit 0

fi

