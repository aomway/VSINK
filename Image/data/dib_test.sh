#! /bin/sh

echo 54 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio54/direction
echo 0 > /sys/class/gpio/gpio54/value
usleep 10000
echo 1 > /sys/class/gpio/gpio54/value