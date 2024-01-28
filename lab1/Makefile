# Makefile for all the programs in the lab1/src and lab1/assign directories

# Compiler (modify if necessary)
CC         = gcc

# Compiler command for object files
COMPILE    = $(CC) -c

# Linker command for creating executables
LINK       = $(CC) -o

# Specify the name of the directory where the assignment files are located.
ASSIGN_DIR = assign

# Specify the name of the directory where executables will be stored.
BIN_DIR    = bin

# Specify the name of the directory where object files will be stored.
BUILD_DIR  = build

# Specify the name of the directory where source files are located.
SRC_DIR    = src

# Specify the name of the executable files that will be created.
PROGRAMS   = $(BIN_DIR)/comic.out \
						 $(BIN_DIR)/calculator.out \
						 $(BIN_DIR)/minimal.out \
						 $(BIN_DIR)/pause.out \

# Allow make all and make clean to be executed even if there is a file
# named 'all' or 'clean'.
.PHONY: all clean

# Default rule
all: $(BIN_DIR) $(BUILD_DIR) $(PROGRAMS)

# Make clean rule
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

# Rules for creating the executables

$(BIN_DIR)/comic.out: $(BUILD_DIR)/comic.o
	$(LINK) $@ $^

$(BIN_DIR)/calculator.out: $(BUILD_DIR)/calculator.o
	$(LINK) $@ $^

$(BIN_DIR)/minimal.out: $(BUILD_DIR)/minimal.o
	$(LINK) $@ $^

$(BIN_DIR)/pause.out: $(BUILD_DIR)/pause.o
	$(LINK) $@ $^

# Rules for creating the object files

$(BUILD_DIR)/comic.o: $(SRC_DIR)/comic.c
	$(COMPILE) $^ -o $@

$(BUILD_DIR)/calculator.o: $(ASSIGN_DIR)/calculator.c
	$(COMPILE) $^ -o $@

$(BUILD_DIR)/minimal.o: $(SRC_DIR)/minimal.c
	$(COMPILE) -ansi $^ -o $@

$(BUILD_DIR)/pause.o: $(SRC_DIR)/pause.c
	$(COMPILE) $^ -o $@

# Rules for creating the directories

$(BIN_DIR):
	mkdir $@

$(BUILD_DIR):
	mkdir $@
