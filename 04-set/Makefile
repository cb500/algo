# -*- Makefile -*-

# Binaries
CC    = gcc
MKDIR = mkdir -p

# Folders and paths
INCDIR    = ./include
SRC    	  = src
BUILD_DIR = objs

# CC flags and libs
CFLAGS = -g -Wall -I$(INCDIR)
LIBS   =

# Binary name
BIN  = set

# Source files and object files
SRCS = 
OBJS = $(addprefix $(BUILD_DIR)/,$(patsubst %.c,%.o,$(SRCS)))

.PHONY: all clean

all: directories $(BIN)

directories:
	${MKDIR} ${BUILD_DIR}

$(BUILD_DIR)/%.o: $(SRC)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJS)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -Rf $(BUILD_DIR)