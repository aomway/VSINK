#! /bin/sh
echo "clr disp..."
#disable display
echo 0 > /sys/class/gpio/gpio60/value
usleep 10000
#resetn display
echo 0 > /sys/class/gpio/gpio57/value
usleep 10000
