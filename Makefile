CXX = clang++
CXX_FLAGS = -std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
	bin/exec
	rm -f bin/*

tests: bin/tests
	bin/tests
	rm -f bin/*

bin/exec: ./src/*.cpp ./entry/main.cc ./includes/cs225/*.cpp ./includes/lodepng/*.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: ./src/*.cpp ./tests/tests.cc obj/catch.o ./includes/cs225/*.cpp ./includes/lodepng/*.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -f bin/*