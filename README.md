# How to Use GcRay
The GcRay is a cross-platform lightwight software for generating DTU datasets-like datasets in the refractive scene built with cmake.

In Linux, use cmake to build it:
```
cd ./build
cmake ..
make
```
In windows , you have to delete the .so files in `lib`, and cmake this project by your self since different environments are different here:
```
cd lib
rm *.so
cd ../build
cmake ..
make
```