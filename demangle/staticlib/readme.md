```
$ nm libmylib.a 

mylib.o:
0000000000000010 T bar      // demangled
0000000000000020 T rand     // demangled
0000000000000000 T _Z3foov  // mangled
```

* conslusion
  * If extern "C" is not specified, function is exported mangled(foo).
  * If extern "C" is specified, function is exported delemgned(bar).
  * If function is already declared, it follows the prior declaration(rand).
