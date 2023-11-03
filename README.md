# Overview

To be clear.   Personally, I think [system(const char *)](https://linux.die.net/man/3/system) is one of the most overused and abused api calls in Linux/Unix/OSX/Windows.  I have seen invocations as ridiculous as:

```C
    system("sleep 1") ;
```

That being said, I've also seen in way too many places terrible error-prone practices building up strings to execute.  

This library is an attempt to at least provide a cleaner way of executing them, while leveraging the gnu compiler suite execellent [checking of printf style](https://gcc.gnu.org/onlinedocs/gcc-3.1.1/gcc/Function-Attributes.html) parameters.


