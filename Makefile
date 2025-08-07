# Compiler Options
CC = gcc
CXX = g++

# Directories
BUILD_DIR := build
CONFIGURE_STAMP := $(BUILD_DIR)/configure.stamp

.PHONY: configure
configure: $(CONFIGURE_STAMP)
$(CONFIGURE_STAMP): CMakeLists.txt
	CC=$(CC) CXX=$(CXX) cmake -S . -B build
	@touch $(BUILD_DIR)/configure.stamp

.PHONY: build
build: configure
	cmake --build build

.PHONY: clean
clean:
	rm -rf build \
		   imgui.ini

FORMAT_EXCLUDES := ./dependencies/
FORMAT_FILES := $(shell find . -name '*.cpp' -o -name '*.hpp' | grep -v $(FORMAT_EXCLUDES))
.PHONY: format
format: 
	@clang-format -i  $(FORMAT_FILES)
