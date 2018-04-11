How to build `Data_Structure`
===================

on `Windows`
--------
```
$ vcvarsall.bat x86
$ mkdir build
$ cd build
$ cmake -G "NMake Makefiles" ..
$ cmake --build .
```

on `Linux` and `Apple`
------------------
```
$ mkdir build
$ cd build
$ cmake -DCMAKE_OSX_ARCHITECTURES=i386 ..
$ cmake --build .
```

How to modify the encoding on the `Windows cmd`
================================================

`UTF8`
----
1. To change encoding
```
C:\ CHCP 65001
```

2. To change font to `Lucida Console`

`English`
-------
1. To change encoding
```
C:\ CHCP 437
```

`Simplified Chinese`
------------------
1. To change encoding
```
C:\ CHCP 936
```