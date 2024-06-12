#!/bin/sh

xset s off -dpms
xrandr --output DP-2 --mode 1920x1080 --rate 144
setxkbmap -layout "us,ru" -option "grp:alt_shift_toggle"

while true; do
    xsetroot -name "$(date +"%d %h %H:%M")"
	sleep 30
done&

pipewire&
exec dwm
