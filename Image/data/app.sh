#! /bin/sh


ifconfig lo up
ifconfig eth0 up
ifconfig eth0 192.168.1.11
cd /data
cp ./memtool /usr/bin/
tar -xvf ./lib_jpeg.tar -C /usr
tar -xvf ./ffmpeg_lib.tar -C /tmp
cp /data/ffmpeg /usr/bin
export LD_LIBRARY_PATH="/tmp/lib"
mount /dev/mmcblk0p1 /media

#cp -rf /root/lmatio/* /usr/lib/
#tar xf rtp_opus_install.tar -C /tmp
#cp /tmp/rtp_opus_install/lib/* /usr/lib
#./adv7511_sz 2 &
echo 54 > /sys/class/gpio/export
echo 55 > /sys/class/gpio/export
echo 56 > /sys/class/gpio/export
echo 57 > /sys/class/gpio/export
echo 58 > /sys/class/gpio/export
echo 59 > /sys/class/gpio/export
echo 60 > /sys/class/gpio/export
echo 64 > /sys/class/gpio/export
echo 65 > /sys/class/gpio/export
echo 66 > /sys/class/gpio/export
echo 78 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio54/direction
echo out > /sys/class/gpio/gpio55/direction
echo out > /sys/class/gpio/gpio56/direction
echo out > /sys/class/gpio/gpio57/direction
echo out > /sys/class/gpio/gpio58/direction
echo out > /sys/class/gpio/gpio59/direction
echo out > /sys/class/gpio/gpio60/direction
echo out > /sys/class/gpio/gpio78/direction
echo out > /sys/class/gpio/gpio64/direction
echo out > /sys/class/gpio/gpio65/direction
echo out > /sys/class/gpio/gpio66/direction
echo 1 > /sys/class/gpio/gpio55/value
echo 1 > /sys/class/gpio/gpio64/value

#cd /media
#./update_qspi.sh 

#memtool -32 f800a008=f
#memtool -32 f800a004=77
memtool -32 f8008008=f
memtool -32 f8008004=77
#memtool -32 f8009008=f
#memtool -32 f8009004=77
#memtool -32 f800061c=5555
memtool -32 f800061c=5050
#./djpeg -bmp ./aomway.jpg > /media/aomway.bmp
#./upload.sh
#./display_reset.sh
#./dec_reset_only.sh
#./zynd_decoder &
#./udp_get_ts &
#./udp_get_iwinfo 8010 > /dev/null &
#./memset_logo 65535
#./mavlink_proxy_vsink > /dev/null &
#./osd_anjian &
#./write_ts &
