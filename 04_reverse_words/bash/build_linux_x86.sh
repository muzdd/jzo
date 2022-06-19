#!/bin/bash
if [ $# -eq 1 ]; then
  export INSTALL_PREFIX=$1

else
  echo "Please specifiy the install path"
  echo "$0 install_path"
  exit -1

fi

if [ ! -d build_linux_x86 ]; then
    mkdir -p build_linux_x86
fi
cd build_linux_x86


BUILD_DIR="linux-x86-release"
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

cd ../../
DEMO_DIR=build_linux_x86/$BUILD_DIR/test_demo
if [ ! -d $DEMO_DIR ]; then
    mkdir -p $DEMO_DIR
fi

echo "build_dir:$BUILD_DIR"
cp -rf build_linux_x86/$BUILD_DIR/test/test $DEMO_DIR
