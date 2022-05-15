#!/bin/bash
if [ ! -d build_macOS_x86 ]; then
    mkdir -p build_macOS_x86
fi
cd build_macOS_x86


BUILD_DIR="macOS-release"
if [ ! -d $BUILD_DIR ]; then
    mkdir -p $BUILD_DIR
fi
cd $BUILD_DIR


export ANDROID_NDK=/home/lixintao/Desktop/3rdparty/android-ndk-r17c
if [ "$ANDROID_NDK" = "" ]; then
    echo "ERROR: Please set ANDROID_NDK_HOME environment"
    exit
fi

cmake ../.. 
make -j4 VERBOSE=1

