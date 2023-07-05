# Makefile

# Variáveis
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = src
BIN_DIR = bin
TEST_DIR = $(SRC_DIR)/tests
DOC_DIR = doc

# Arquivos fonte
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SOURCES))

# Inclusão das pastas classes, constants e utils
INCLUDE_DIRS = -I$(SRC_DIR)/classes -I$(SRC_DIR)/constants -I$(SRC_DIR)/utils -I$(SRC_DIR)/assets

# Nome do executável
EXECUTABLE = $(BIN_DIR)/main

# Nome do executável de testes
TEST_EXECUTABLE = $(BIN_DIR)/tests

# Comandos
.PHONY: all clean doc

all: $(EXECUTABLE)

# Compilação do programa principal
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $^ -o $@

# Compilação dos arquivos de objeto
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Compilação e execução dos testes
test:
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(TEST_DIR)/test.cpp -o $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

# Geração da documentação com Doxygen
doc:
	doxygen Doxyfile

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(DOC_DIR)/*
