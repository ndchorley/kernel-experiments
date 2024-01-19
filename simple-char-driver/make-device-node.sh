#!/bin/bash

rm -f /dev/simplechar

major=$(grep simplechar /proc/devices | awk '{print $1}')

mknod /dev/simplechar c $major 0
