CXX = g++
CXXFLAGS = -pedantic -pedantic-errors -Wall -Werror -std=c++14
HEADERS = src/headers
SRC_FILES = src/*.cpp

run : main
	./main

main : ip.o acl.o
	$(CXX) $(CXXFLAGS) -I $(HEADERS) ip.o acl.o src/main.cpp -o main

ip.o: src/headers/ip.h src/ip.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -c src/ip.cpp -o ip.o

acl.o: src/headers/std-acl.h src/std-acl.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -c src/std-acl.cpp -o acl.o


.PHONY : clean
clean :
	rm -rf *.o main