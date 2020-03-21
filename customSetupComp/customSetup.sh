#!/bin/sh
# Copyright 2019 Tyler Listoe 
#
# Setup WiFi stuff during boot

source /etc/run.env

case "$1" in
    start)
	sleep 20
#	ifup wlan1
#	/legato/systems/current/bin/wifi ap setssid OptimusGearTest_AF
#	/legato/systems/current/bin/wifi ap setdriver 1
#	/legato/systems/current/bin/wifi ap setmaxclients 5
#	/legato/systems/current/bin/wifi ap setsecurityproto 1
#	/legato/systems/current/bin/wifi ap setpassphrase optimus1234
#	/legato/systems/current/bin/wifi ap setdiscoverable 1
#	/legato/systems/current/bin/wifi ap setchannel 11
#	/legato/systems/current/bin/wifi ap start wlan1
#	ifconfig wlan1 192.168.20.1 netmask 255.255.255.0 up
#	echo "dhcp-range=wlan1,192.168.20.10,192.168.20.100,24h" >> /etc/dnsmasq.d/dnsmasq.wlan.conf
#	/etc/init.d/dnsmasq start
	/legato/systems/current/bin/gnss start
	modprobe sdhci-msm
	mkdir -p /mnt/userrw/sdcard
	/bin/mount -t auto -o sync /dev/mmcblk0p1 "/mnt/userrw/sdcard"
        ;;
    monitor)
        ;;
    stop)
        ;;
    *)
        exit 1
        ;;
esac

exit 0
