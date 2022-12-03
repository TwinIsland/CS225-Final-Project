CXX = clang++
CXX_FLAGS = -std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
	bin/exec
	rm -f bin/*

tests: bin/tests
	bin/tests
	rm -f bin/*

g_test: bin/g_exec
	bin/g_exec
	rm -f bin/*

calc_bc: bin/bc_exec
	bin/bc_exec

bin/exec: ./src/*.cpp ./entry/main.cc ./includes/cs225/*.cpp ./includes/lodepng/*.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/g_exec: ./src/graph.cpp ./src/utils.cpp ./entry/main.cc
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/bc_exec: ./src/graph.cpp ./src/utils.cpp ./entry/calc_bc.cc
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: ./src/*.cpp ./tests/tests.cc obj/catch.o ./includes/cs225/*.cpp ./includes/lodepng/*.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -f bin/*