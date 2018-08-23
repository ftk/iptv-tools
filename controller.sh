#!/bin/bash
# Allows user to control their DLNA renderer with keyboard to change TV channels from predefined playlist.
# Features:
# Select random channel from a category (press enter)
# Search for a channel by name (supports en and ru keyboard layouts) (press `, then a channel name substring, then enter)
# Extracts TV guide via get-programme.pl script

# See startcontroller.sh for keyboard configuration info

col() { gawk -F'\t' "{print \$${1}}"; }
#getcol() { echo "$1" | col "$2"; }

filter() { gawk -F'\t' "BEGIN{IGNORECASE=1;} ${1} {print}"; }

selectrand() { sort -R --random-source=/dev/random | head -n 1; }

play() {
    echo playing "$ch"

    # async stop
    ./upnp.sh stop &
    
    #echo "$ch" | col 1
    history+=("$ch")
    #echo ./upnp.sh stop uri "$(echo "$ch" | col 2)" play &
    local name="$(echo "$ch" | col 1)"
    local prog="$(perl get-programme.pl "$name")"
    [ ! -z "$prog" ] && name="$name ($(echo "$prog" | col 2) $(echo "$prog" | col 1))"
    wait # wait for stop
    ./upnp.sh name "$name" uri "$(echo "$ch" | col 2)" play  &
}

state=0 # 0 - random by category, 1 - searching

history=()

category='Фильмы'

searchline=''

#echo blacklisted:
#cat blacklist.txt | col 1


while read key
do
    echo pressed $key...
    key=$(echo $key | tr A-Z a-z)
    if [ "$state" = 0 ]
    then
        
        if [ "$key" = "enter" -o "$key" = "kpenter" ]; then
            ch=blacklist
            while grep -q "^$(echo "$ch" | col 1)$" blacklist.txt
            do
                ch=$(cat tv.txt | filter "\$3 == \"$category\"" | selectrand)
            done
            play
        elif [ "$key" = "m" ]; then # define categories and keys here
            category='Фильмы'
        elif [ "$key" = "u" ]; then
            category='Музыка'
        elif [ "$key" = "n" ]; then
            category='Новостные'
        elif [ "$key" = "c" ]; then
            category='Общие'
        elif [ "$key" = "e" ]; then
            category='Познавательные'
        elif [ "$key" = "t" ]; then
            category='Развлекательные'
        elif [ "$key" = "r" ]; then
            category='Региональные'
        elif [ "$key" = "s" ]; then
            category='Спорт'
        elif [ "$key" = "h" ]; then
            category='Детские'
        elif [ "$key" = "b" ]; then
            echo prev: $ch
            echo "$ch" | col 1 >> blacklist.txt
        elif [ "$key" = "grave" ]; then
            state=1
            searchline=''
        elif [ "$key" = "backspace" ]; then
            unset history[-1]
            ch="${history[-1]}"
            [ ! -z "$ch" ] && play
            unset history[-1]
        elif [ "$key" = "leftshift" ]; then
            if [ "$(cat /tmp/searchch.txt | wc -l)" -ge 2 ]
            then
                newch="$ch"
                while [ "$newch" == "$ch" ]; do newch="$(cat /tmp/searchch.txt | selectrand )"; done
                [ ! -z "$newch" ] && ch="$newch" && play
            fi
        fi
        
    else # state != 0
        if [ "$key" = "esc" ]; then
            state=0
        elif [ "$key" = "grave" ]; then
            searchline=''
        elif [ "$key" = "insert" ]; then # wildcard
            searchline="${searchline}.*"
        elif [ "$key" = "home" ]; then # math only beginning or end
            [ -z "$searchline" ]  && searchline="^" || searchline="${searchline}$"
        elif [ "$key" = "backspace" ]; then
            searchline="${searchline::-1}"
        elif [ "$key" = "enter" -o "$key" = "kpenter" ]; then
            # search in english layout
            cat tv.txt | filter "\$1 ~ /$searchline/" > /tmp/searchch.txt
            # search in russian layout
            cat tv.txt | LC_ALL=ru_RU.utf8 filter "\$1 ~ /$(echo $searchline | ./tr-en-ru.sh | sed 's/ рв$/ hd/;s/ю\*/.*/g' )/" >> /tmp/searchch.txt
            ch="$(cat /tmp/searchch.txt | selectrand )"
            state=0
            [ ! -z "$ch" ] && play
        else
            key="$(echo $key | sed 's/leftbrace/[/;s/rightbrace/]/;s/semicolon/;/;s/apostrophe/'"'"'/;s/comma/,/;s/dot/./;s/space/ /;')"
            searchline="${searchline}${key}"
        fi
    fi

    if [ "$key" = "tab" ]; then
        [ ! -z "$ch" ] && play
    elif [ "$key" = "delete" ]; then
        # restart controller
        exec ./controller.sh
    elif [ "$key" = "end" ]; then # stop playback
        ./upnp.sh stop
        #hist=()
    elif [ "$key" = "kpplus" ]; then
        ./upnp.sh volup
    elif [ "$key" = "kpminus" ]; then
        ./upnp.sh voldown
    elif [ "$key" = "kpasterisk" ]; then
        rm tv.txt && ln -s iptv-as.txt tv.txt
    elif [ "$key" = "kpslash" ]; then
        rm tv.txt && ln -s iptv-nb.txt tv.txt
    fi

    
done
