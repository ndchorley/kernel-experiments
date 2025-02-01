#!/bin/bash

make -C ~/linux-$(uname -r) M=$(pwd) modules
