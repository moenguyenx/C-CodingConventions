# Compiler
# The CC variable specifies the compiler to use.
CC = gcc

# Compiler Flags
# The CFLAGS variable specifies the compiler flags to use.
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

# Directories
# The SRC_DIR, INC_DIR, OBJ_DIR, and BIN_DIR variables specify the directories- 
#-for source files, header files, object files, and binary files, respectively.
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = output

# Files
# 'wildcard' function: substitution reference, replacing one substring with another
# The SRC variable uses the wildcard function to find all .c files in the SRC_DIR directory
#######
# 'patsubst' function: $(patsubst PATTERN, REPLACEMENT, TEXT)
# The OBJ variable uses the patsubst function to generate a list of object files from the source files.
#######
# The DEP variable generates a list of dependency files for each object file
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEP = $(OBJ:.o=.d)

# Targets
# The TARGET variable specifies the name and location of the output file.
TARGET = $(BIN_DIR)/program.exe

# PHONY target
# The .PHONY target specifies the phony targets.
# Adding .PHONY to a target will prevent Make from confusing the phony target with a file name
.PHONY: all clean run

# Default target
# The all target is the default target and builds the output file.
# The $(TARGET) target builds the output file from the object files.
all: $(TARGET)

# Build target
# mkdir -p create nested directories, but only if they don't exist already
# $@ evaluates to TARGET
# $< evaluates to first prerequisite
# $^ evaluates to all prerequisites
# @ prevent from printing out the command to console
# The -p flag will create nested directories, but only if they don't exist already.
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR) 
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Build Complete."

# Object files
# The $(OBJDIR)/%.o target compiles each .c file into an object file.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -MP -c $< -o $@ 

# Clean target
# The clean target removes all object files and the output file.
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Clean complete."

# Run target
# The run target runs the output file and prints the start and stop times.
run: $(TARGET)
	@echo "Starting program..."
	@echo "Start time: $$(date)"
	./$(TARGET)
	@echo "Stop time: $$(date)"

# Include dependencies
-include $(DEP)
















