# Makefile for all the programs in the lab1/src and lab1/assign directories

# Compiler (modify if necessary)
CC         = gcc

# Compiler command for object files
COMPILE    = $(CC) -c

# Linker command for creating executables
LINK       = $(CC) -o

# Specify the name of the directory where executables will be stored.
BIN_DIR    = bin

# Specify the name of the directory where object files will be stored.
BUILD_DIR  = build

# Specify the name of the directory where source files are located.
SRC_DIR    = src

# Specify the name of the executable files that will be created.
PROGRAMS   = $(BIN_DIR)/fork.out $(BIN_DIR)/sleep.out $(BIN_DIR)/concurrency.out \
						 $(BIN_DIR)/wait.out $(BIN_DIR)/ls.out $(BIN_DIR)/micro.out

# Allow make all and make clean to be executed even if there is a file
# named 'all' or 'clean'.
.PHONY: all clean

# Default rule
all: $(PROGRAMS)

# Make clean rule
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

# Rules for creating the executables

$(BIN_DIR)/fork.out: $(BUILD_DIR)/fork.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/sleep.out: $(BUILD_DIR)/sleep.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/concurrency.out: $(BUILD_DIR)/concurrency.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/wait.out: $(BUILD_DIR)/wait.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/ls.out: $(BUILD_DIR)/ls.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/micro.out: $(BUILD_DIR)/micro.o $(BIN_DIR)
	$(LINK) $@ $<

# Rules for creating the object files

$(BUILD_DIR)/fork.o: $(SRC_DIR)/fork.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/sleep.o: $(SRC_DIR)/sleep.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/concurrency.o: $(SRC_DIR)/concurrency.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/wait.o: $(SRC_DIR)/wait.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/ls.o: $(SRC_DIR)/ls.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/micro.o: $(SRC_DIR)/micro.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

# Rules for creating the directories

$(BIN_DIR):
	mkdir $@

$(BUILD_DIR):
	mkdir $@
