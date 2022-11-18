CXX = clang++
CXX_FLAGS = -std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

# SRC:
# 	./src/solution.cc ./src/driver.cc ./src/graph.cpp ./src/utils.cpp

exec: bin/exec
	bin/exec

tests: bin/tests
	bin/tests

bin/exec: ./src/solution.cc ./src/graph.cpp ./src/utils.cpp ./entry/main.cc
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: ./tests/tests.cc obj/catch.o ./src/solution.cc ./src/graph.cpp ./src/utils.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean