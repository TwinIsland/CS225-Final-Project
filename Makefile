CXX = clang++
CXX_FLAGS = -std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
	bin/exec
	rm -f bin/*

tests: bin/tests
	bin/tests
	rm -f bin/*

bin/exec:  ./src/*.cc ./src/*.cpp ./entry/main.cc
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: ./src/*.cc ./src/*.cpp ./tests/tests.cc obj/catch.o
	$(CXX) $(CXX_FLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -f bin/*