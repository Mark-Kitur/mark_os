#!/bin/sh
rfkill unblock wifi
ip link set wlan0 up
