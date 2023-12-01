
![build status](https://github.com/AndrewOfC/systemf/actions/workflows/build_and_test.yaml/badge.svg)

# Overview

To be clear.   Personally, I think [system(const char *)](https://linux.die.net/man/3/system) is one of the most overused and abused api calls in Linux/Unix/OSX/Windows.  I have seen invocations as ridiculous as:

```C
    system("sleep 1") ;
```

That being said, I've also seen in way too many places terrible error-prone practices building up strings to execute.  

This library is an attempt to at least provide a cleaner way of executing them, while leveraging the gnu compiler suite's execellent [checking of printf style](https://gcc.gnu.org/onlinedocs/gcc-3.1.1/gcc/Function-Attributes.html) parameters.


# Examples

## From

```C
#include <stdlib.h>

char buffer[64] ;
sprintf(buffer, "sleep %d", 5) ;
system(buffer) ;
```

## To

```C
#include <systemf/systemf.h>

systemf("sleep %d", 5) ;
```

# Building

```
git clone https://github.com/AndrewOfC/systemf.git
cd systemf
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release
make -j install
```

## Uninstalling

```
cd build
rm `cat install_manifest.txt`
```