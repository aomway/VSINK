#! /bin/sh
echo "set disp..."
#enable display
echo 1 > /sys/class/gpio/gpio60/value
usleep 10000
#release display
echo 1 > /sys/class/gpio/gpio57/value
usleep 10000
