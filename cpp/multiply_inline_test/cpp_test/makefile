all:
	g++ -c -o multiply.o multiply.cpp        -g -flto -O2
	g++ -c -o cpp_test.o cpp_test.cpp        -g -flto -O2
	g++    -o cpp_test multiply.o cpp_test.o -g -flto -O2

clean:
	rm -rf *.o
	rm -rf cpp_test

rebuild: clean all
