#!/bin/bash
echo 'KERNEL=="video*", SUBSYSTEMS=="usb",ATTRS{idVendor}=="0edc",ATTRS{idProduct}=="2050",KERNELS=="1-1",NAME="video0",SYMLINK+="ucar_video"' >>  /etc/udev/rules.d/ucar.rules # type-c摄像头
service udev reload
sleep 2
service udev restart

echo 'source /home/ucar/ucar_ws/devel/setup.bash' >> /home/ucar/.bashrc # 小车底盘

