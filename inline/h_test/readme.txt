$ qmake

$ make
g++ -c -std=c++11 -O2  -I. -I../common -I/home/gilgil/Qt5.4.1/5.4/gcc_64/mkspecs/linux-g++ -o h_test.o h_test.cpp
g++ -c -std=c++11 -O2  -I. -I../common -I/home/gilgil/Qt5.4.1/5.4/gcc_64/mkspecs/linux-g++ -o gstacktrace.o ../common/gstacktrace.cpp
g++ -rdynamic -o h_test h_test.o gstacktrace.o    

$ ./h_test 
3
******** stack trace ******** (9744)
  ./h_test : GStackTrace::dump()+0xff
  ./h_test : main()+0x25
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf5
  ./h_test() [0x401acf]
6
