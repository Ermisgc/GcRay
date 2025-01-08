# How to BUILD GcRay
The GcRay is a cross-platform lightwight software for generating DTU datasets-like datasets in the refractive scene built with cmake.

Before you use GcRay, you have to make sure that `gcc` and `povray` have been installed in your computer:
```
sudo apt update
sudo apt-install gcc
sudo apt-install povray
```

## Option1. build this project by yourself
In Linux, use `cmake` to build it:
```
mkdir build
cd ./build
cmake ..
make
```
In windows , you have to delete the .so files in `lib`, and cmake this project by your self since different environments are different here:
```
mkdir build
cd lib
rm *.so
cd ../build
cmake ..
make
```

## Option2. build this project through .sh file
In Linux, you can do like this:
```
chomd -x generate.sh
./generate.sh
```