# Makefile for all the programs in the lab2/src directory

# A Makefile generally consists of a series of rules. Each rule
# generally looks like this:
# target: dependencies
# 	command

# The target is the name of the file that must be generated. The
# dependencies are files that the target depends on. The command is
# the command that must be executed to generate the target.

# First, we define some variables. Variables are used to avoid
# repetition. For example, we define the variable CC to be the name
# of the compiler. Then, we can use $(CC) instead of gcc in the
# rules. If we want to change the compiler, we only have to change
# the definition of CC.

# Compiler (modify if necessary)
CC        = gcc

# Compiler command for object files
COMPILE   = $(CC) -c

# Linker command for creating executables
LINK      = $(CC) -o

# Specify the name of the directory where executables will be stored.
BIN_DIR   = bin

# Specify the name of the directory where object files will be stored.
BUILD_DIR = build

# Specify the name of the directory where source files are located.
SRC_DIR   = src

# Specify the name of the executable files that will be created.
PROGRAMS  = $(BIN_DIR)/flight.out \
						$(BIN_DIR)/hello_fullname.out \
						$(BIN_DIR)/hello_user.out \
						$(BIN_DIR)/point_of_sale.out \
						$(BIN_DIR)/sequence_of_flights.out \
						$(BIN_DIR)/soccer_teams.out \
						$(BIN_DIR)/upper_lower.out

# This .PHONY rule keeps make from doing something with a file named
# 'all' or 'clean'. It tells make that 'all' and 'clean' are not real
# files, but are just names for rules. This rules are executed when
# you type 'make all' or 'make clean'.
.PHONY: all clean

# The all rule creates all the executables that are part of the
# program. It is the default rule, so you can just type 'make' to
# execute it.
all: $(PROGRAMS)

# The clean rule is used to remove files that are generated by the
# compiler or by make.

# The @ symbol tells make not to print the command to the screen

clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

# The following rules create the executables. Each executable depends
# on the corresponding object file. The object files are created by
# the rules below.

# The $@ is a special variable that refers to the target of the rule.
# In this case, it refers to $(BIN_DIR)/flight.out.

# $< is a special variable that refers to the first dependency of the
# rule. In this case, it refers to $(BUILD_DIR)/sequence_of_flights.o.

$(BIN_DIR)/flight.out: $(BUILD_DIR)/flight.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/hello_fullname.out: $(BUILD_DIR)/hello_fullname.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/hello_user.out: $(BUILD_DIR)/hello_user.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/point_of_sale.out: $(BUILD_DIR)/point_of_sale.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/sequence_of_flights.out: $(BUILD_DIR)/sequence_of_flights.o \
																		$(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/soccer_teams.out: $(BUILD_DIR)/soccer_teams.o $(BIN_DIR)
	$(LINK) $@ $<

$(BIN_DIR)/upper_lower.out: $(BUILD_DIR)/upper_lower.o $(BIN_DIR)
	$(LINK) $@ $<

# The following rules create the object files. Each object file
# depends on the corresponding source file and any header files
# included by the source file. The object files are created in the
# build directory.

# An object file contains machine code that has not yet been linked
# with other object files and libraries to produce an executable
# program.

$(BUILD_DIR)/flight.o: $(SRC_DIR)/flight.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/hello_fullname.o: $(SRC_DIR)/hello_fullname.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/hello_user.o: $(SRC_DIR)/hello_user.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/point_of_sale.o: $(SRC_DIR)/point_of_sale.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/sequence_of_flights.o: $(SRC_DIR)/sequence_of_flights.c \
																		$(SRC_DIR)/sequence_of_flights.h \
																		$(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/soccer_teams.o: $(SRC_DIR)/soccer_teams.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(BUILD_DIR)/upper_lower.o: $(SRC_DIR)/upper_lower.c $(BUILD_DIR)
	$(COMPILE) $< -o $@

# The following rules create the build and bin directories.

$(BIN_DIR):
	mkdir $@

$(BUILD_DIR):
	mkdir $@
