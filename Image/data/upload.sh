#!/bin/sh

min=0
if [ -f /media/AOMWAYHD_RX.tar ];then

	
	tar -xvf /media/AOMWAYHD_RX.tar -C /tmp/

	version1=$(cat /tmp/AOMWAYHD_RX/VERSION)
	version2=$(cat /data/VERSION)

	if [ $version1 = $version2 ];then
		echo "do not upload"

	else
		echo "upload"
		cp -rf /tmp/AOMWAYHD_RX/* /data
		while [ $min -le 40 ]
		do
			min=`expr $min + 1`
			echo 0 > /sys/class/gpio/gpio65/value
			usleep 100000
			echo 1 > /sys/class/gpio/gpio65/value
			usleep 100000
		done		
		sync
		while [ 1 -gt 0 ]
		do
			echo 1 > /sys/class/gpio/gpio65/value
		done
		
	fi
fi
