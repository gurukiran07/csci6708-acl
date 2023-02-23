CXX = g++
CXXFLAGS = -std=c++11 -pedantic -pedantic-errors -Wnarrowing -Wall -Werror
HEADERS = src/headers
SRC_FILES = src/*.cpp

run : main
	./main

main : ip.o acl.o ext.o src/main.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) ip.o acl.o ext.o src/main.cpp -o main

ip.o : src/headers/ip.h src/ip.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -c src/ip.cpp -o ip.o

acl.o : src/headers/std-acl.h src/std-acl.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -c src/std-acl.cpp -o acl.o

ext.o : src/headers/ext-std-acl.h src/ext-std-acl.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) -c src/ext-std-acl.cpp -o ext.o

.PHONY : clean
clean :
	rm -rf *.o main