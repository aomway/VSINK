#! /bin/sh
echo "reset decoder..."
#disable ts in
echo 0 > /sys/class/gpio/gpio58/value
usleep 200000

echo 0 > /sys/class/gpio/gpio56/value
usleep 20000
#reset decode
echo 1 > /sys/class/gpio/gpio55/value
usleep 10000

echo 1 > /sys/class/gpio/gpio56/value
usleep 10000
#release decode
echo 0 > /sys/class/gpio/gpio55/value
usleep 100000
#enable ts in
echo 1 > /sys/class/gpio/gpio58/value
usleep 20000

