# Makefile

# This file was created by ChatGPT.

# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = src
BIN_DIR = bin
TEST_DIR = $(SRC_DIR)/tests
DOC_DIR = doc

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SOURCES))

# Include directories for classes, constants, utils, and assets
INCLUDE_DIRS = -I$(SRC_DIR)/classes -I$(SRC_DIR)/constants -I$(SRC_DIR)/utils -I/assets 

# Executable name
EXECUTABLE = $(BIN_DIR)/main

# Test executable name
TEST_EXECUTABLE = $(BIN_DIR)/tests

# Commands
.PHONY: all clean doc

all: $(EXECUTABLE)

# Compilation of the main program
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $^ -o $@

# Compilation of object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Compilation and execution of tests
test:
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(TEST_DIR)/test.cpp -o $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

# Generation of documentation using Doxygen
doc:
	doxygen Doxyfile

# Cleaning of generated files
clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(DOC_DIR)/*

# Creation of bin directory if it doesn't exist
$(shell mkdir -p $(BIN_DIR))
