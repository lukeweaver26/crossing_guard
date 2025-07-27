# Compiler Options
CC = gcc
CXX = g++
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

.PHONY: setup
setup:
	CC=$(CC) CXX=$(CXX) cmake -S . -B build

.PHONY: build
build: setup
	cmake --build build

.PHONY: clean
clean:
	rm -rf build

FORMAT_EXCLUDES := ./dependencies/
FORMAT_FILES := $(shell find . -name '*.cpp' -o -name '*.hpp' | grep -v $(FORMAT_EXCLUDES))
.PHONY: format
format: 
	@clang-format -i  $(FORMAT_FILES)
