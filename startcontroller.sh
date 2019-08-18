# change directory to playlist
cd ~/pls

# select event device corresponding to your keyboard (see /proc/bus/input/devices for event devices)

event='event2'

# or select by parsing devices file (for example, A4tech keyboard)
event="$(cat /proc/bus/input/devices | awk  'BEGIN{RS="\n\n";FS="\n";OFS="\t";}{print $1,$2,$3,$4,$5,$6,$7}' | grep -i a4tech | grep kbd | grep -o event[0-9] || echo event2)"

~/input/input /dev/input/${event} --rel all print | ./controller.sh 2>&1 > /var/log/kbcontrol.log

