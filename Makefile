CFLAGS= -std=c11 -Wall -Wextra -pedantic -g -D_XOPEN_SOURCE=700 -fsanitize=address -fno-omit-frame-pointer
LDFLAGS= -fsanitize=address -fno-omit-frame-pointer

ALL: googletest gtest_file

# dependencies
file.o: file.c file.h

gtest_file: gtest_file.o file.o
	g++ -pthread -std=c++11 gtest_file.o file.o -o gtest_file -L./googletest/build/lib -lgtest -fsanitize=address -fno-omit-frame-pointer
gtest_file.o: gtest_file.cpp file.h
	g++ -pthread -std=c++11 -I./googletest/googletest/include -g -c gtest_file.cpp

gtest: gtest_file
	./gtest_file

googletest:
	(git clone git://github.com/google/googletest.git ; cd googletest ; mkdir build ; cd build ; cmake .. ; make)

clean:
	rm -f *.o gtest_file

gclean:
	rm -rf ./googletest
