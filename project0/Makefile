# Makefile for the Pokemon Pikachu project

# Compiler (modify if necessary)
CC          = gcc

# Compiler command for object files
COMPILE     = $(CC) -c

# Linker command for creating executables
LINK        = $(CC) -o

# Specify the name of the directory where the executable will be stored.
BIN_DIR     = bin

# Specify the name of the directory where object files will be stored.
BUILD_DIR   = build

# Specify the name of the directory where source files are located.
SRC_DIR     = src

# Specify the name of the executable file for the project.
PROGRAM     = $(BIN_DIR)/pokemon.out

# Specify the name of all the object files that will be created.
BUILD_FILES = $(BUILD_DIR)/ascii.o $(BUILD_DIR)/pokemon.o

# Allow make all and make clean to be executed even if there is a file
# named 'all' or 'clean'.
.PHONY: all clean

# Default rule
all: $(BIN_DIR) $(BUILD_DIR) $(PROGRAM)

# Make clean rule
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

# Rule for creating the executable file for the project

$(BIN_DIR)/pokemon.out: $(BUILD_FILES)
	@echo "Linking object files..."
	$(LINK) $@ $^
	@echo "Done."
	@echo "Run the program by executing: ./$(BIN_DIR)/pokemon.out"

# Rules for creating the object files

$(BUILD_DIR)/ascii.o: $(SRC_DIR)/ascii.c $(SRC_DIR)/ascii.h
	@echo "Compiling ascii.c..."
	$(COMPILE) $< -o $@

$(BUILD_DIR)/pokemon.o: $(SRC_DIR)/pokemon.c
	@echo "Compiling pokemon.c..."
	$(COMPILE) $^ -o $@

# Rules for creating the directories

$(BIN_DIR):
	@echo "Creating directory: $(BIN_DIR)"
	mkdir $@

$(BUILD_DIR):
	@echo "Creating directory: $(BUILD_DIR)"
	mkdir $@
