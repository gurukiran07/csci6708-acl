CXX = g++
CXXFLAGS = -pedantic -pedantic-errors -Wall -Werror -std=c++14
HEADERS = src/headers
SRC_FILES = src/*.cpp


main : src/headers/*.h src/*.cpp
	$(CXX) $(CXXFLAGS) -I $(HEADERS) $(SRC_FILES) -o main

run : main
	./main

.PHONY : clean
clean :
	rm -rf *.o main