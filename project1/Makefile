# Makefile for the Real Wizard Chess project

# Compiler (modify if necessary)
CC          = gcc

# Compiler command for object files
COMPILE     = $(CC) -c -Wall -pthread

# Linker command for creating executables
LINK        = $(CC) -o

# Specify the name of the directory where the executable will be stored.
BIN_DIR     = bin

# Specify the name of the directory where object files will be stored.
BUILD_DIR   = build

# Specify the name of the directory where source files are located.
SRC_DIR     = src

# Specify the name of the executable file for the project.
PROGRAM     = $(BIN_DIR)/wizard_chess.out

# Specify the name of all the object files that will be created.
BUILD_FILES = $(BUILD_DIR)/wizard_chess.o $(BUILD_DIR)/chessboard.o \
							$(BUILD_DIR)/piece.o $(BUILD_DIR)/pipe.o \
							$(BUILD_DIR)/movements.o $(BUILD_DIR)/threadmove.o $(BUILD_DIR)/signalP.o

# Allow make all and make clean to be executed even if there is a file
# named 'all' or 'clean'.
.PHONY: all clean

# Default rule
all: $(PROGRAM)

# Make clean rule
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

# Rule for creating the executable file for the project

$(BIN_DIR)/wizard_chess.out: $(BIN_DIR) $(BUILD_FILES)
	@echo "Linking object files..."
	$(LINK) $@ $(BUILD_FILES)
	@echo "Done."
	@echo "Run the program by executing: ./$(BIN_DIR)/wizard_chess.out"

# Rules for creating the object files

$(BUILD_DIR)/chessboard.o: $(SRC_DIR)/chessboard.c $(SRC_DIR)/chessboard.h $(BUILD_DIR)
	@echo "Compiling chessboard.c..."
	$(COMPILE) $< -o $@

$(BUILD_DIR)/pipe.o: $(SRC_DIR)/pipe.c $(SRC_DIR)/pipe.h $(BUILD_DIR)
	@echo "Compiling pipe.c..."
	$(COMPILE) $< -o $@

$(BUILD_DIR)/movements.o: $(SRC_DIR)/movements.c $(SRC_DIR)/movements.h $(BUILD_DIR)
	@echo "Compiling movements.c..."
	$(COMPILE) $< -o $@

$(BUILD_DIR)/threadmove.o: $(SRC_DIR)/threadmove.c $(SRC_DIR)/threadmove.h $(BUILD_DIR)
	@echo "Compiling threadmove.c..."
	$(COMPILE) $< -o $@

$(BUILD_DIR)/signalP.o: $(SRC_DIR)/signalP.c $(SRC_DIR)/signalP.h $(BUILD_DIR)
	@echo "Compiling signalP.c..."
	$(COMPILE) $< -o $@

$(BUILD_DIR)/piece.o: $(SRC_DIR)/piece.c $(SRC_DIR)/piece.h $(BUILD_DIR)
	@echo "Compiling piece.c..."
	$(COMPILE) $< -o $@

$(BUILD_DIR)/wizard_chess.o: $(SRC_DIR)/wizard_chess.c $(BUILD_DIR)
	@echo "Compiling wizard_chess.c..."
	$(COMPILE) $< -o $@

# Rules for creating the directories

$(BIN_DIR):
	@echo "Creating directory: $(BIN_DIR)"
	mkdir $@

$(BUILD_DIR):
	@echo "Creating directory: $(BUILD_DIR)"
	mkdir $@
