#!/bin/bash

#Installation des dépendances
sudo apt-get -y install libopencv-dev build-essential cmake git libgtk2.0-dev pkg-config python-dev python-numpy libdc1394-22 libdc1394-22-dev libjpeg-dev libpng12-dev libtiff4-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libxine-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev libtbb-dev libqt4-dev libfaac-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils unzip

#Telechargement de Opencv 2.4
mkdir opencv
cd opencv
wget https://github.com/Itseez/opencv/archive/2.4.12.zip -O opencv-2.4.12.zip
unzip opencv-2.4.12.zip

#Installation
cd opencv-2.4.12
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_OPENCL=OFF -D WITH_TBB=ON -D WITH_V4L=ON -D WITH_OPENGL=ON ..
make -j $(nproc)
sudo make install

sudo /bin/bash -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig

echo "redémarrage ordinateur requis"
sudo shutdown -r 2