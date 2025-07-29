# libpoly
A C-language library for polynomials

This library is now **developing** library, so may has lots of errors or bugs.
The content of this README file is as of July 29 2025.

## How to install
First, you should create a new folder named ``build``, and change directories to it.

```bash
$ mkdir build
$ cd build
```

Second, use ``cmake`` and ``make`` commands to compile.

```bash
build$ cmake ..
```

Below is a result of ``cmake ..``.

```bash
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: hoge/libpoly/build
```

Doing ``ls``, you can find below-like files or folders.
```bash
build$ ls
CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake
```

```bash
build$ make
```

Below is a result of ``make``

```
[  5%] Building C object CMakeFiles/poly.dir/src/addition.c.o
[ 10%] Building C object CMakeFiles/poly.dir/src/checks.c.o
[ 15%] Building C object CMakeFiles/poly.dir/src/copy.c.o
[ 21%] Building C object CMakeFiles/poly.dir/src/deg.c.o
[ 26%] Building C object CMakeFiles/poly.dir/src/division.c.o
[ 31%] Building C object CMakeFiles/poly.dir/src/gcd.c.o
[ 36%] Building C object CMakeFiles/poly.dir/src/leading.c.o
[ 42%] Building C object CMakeFiles/poly.dir/src/maclaurin_exp.c.o
[ 47%] Building C object CMakeFiles/poly.dir/src/make_mono.c.o
[ 52%] Building C object CMakeFiles/poly.dir/src/make_poly.c.o
[ 57%] Building C object CMakeFiles/poly.dir/src/multiplication.c.o
[ 63%] Building C object CMakeFiles/poly.dir/src/normalize.c.o
[ 68%] Building C object CMakeFiles/poly.dir/src/polynomial.c.o
[ 73%] Building C object CMakeFiles/poly.dir/src/print.c.o
[ 78%] Building C object CMakeFiles/poly.dir/src/set_var.c.o
[ 84%] Building C object CMakeFiles/poly.dir/src/subtraction.c.o
[ 89%] Linking C shared library libpoly.so
[ 89%] Built target poly
[ 94%] Building C object CMakeFiles/test_main.exe.dir/Main.c.o
[100%] Linking C executable test_main.exe
[100%] Built target test_main.exe
```

There is a test file named ``Main.c``, and executing ``test_main.c``, you can execute it.

```bash
build$ ./test.exe

f=1*x^2+2*x^1+1
g=1*x^3+3*x^2+3*x^1+1
h=1*x^3+4*x^2+5*x^1+2
f-g=-1*x^3-2*x^2-1*x^1
10f=10*x^2+20*x^1+10
f*g=1*x^5+5*x^4+10*x^3+10*x^2+5*x^1+1
GCD(f, g) = 1*x^2+2*x^1+1
g=f*(1*x^1+1)+0
cos = -0.000000*x^10+0.000025*x^8-0.001389*x^6+0.041667*x^4-0.500000*x^2+1
```
