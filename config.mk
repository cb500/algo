# -*- Makefile -*-
# Makefile configuration unity
# Author: Charly Batista
# Date: 2021-06-04

# Binaries
CC    = gcc
MKDIR = mkdir -p
VALGRIND = valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all

# GCONV
GCOV = gcovr
GCONV_FLAGS = -r . --html --html-details

#current_dir = $(PWD)
BASE_DIR = $(shell echo `pwd` | sed 's/\/algo\/.*/\/algo/')

# Folders and paths
SRC_DIR	  	= src
INC_DIR   	= include
LIB_DIR		= lib
TST_DIR	  	= test
BUILD_DIR 	= build

SUB_PROJ_DIR = 01-linked_list 02-stack 03-queue 04-set 05-hash_table 06-tree 07-heap 08-graph 09-sorting 10-searching

PROJ_INC_DIR = -I$(BASE_DIR)/$(INC_DIR)
SUB_INC_DIR  = $(addprefix -I$(BASE_DIR)/,$(addsuffix /$(INC_DIR), $(SUB_PROJ_DIR)))
PROJ_LIB_DIR = -L$(BASE_DIR)/$(LIB_DIR) 
SUB_LIB_DIR  = $(addprefix -L$(BASE_DIR)/,$(addsuffix /$(BUILD_DIR), $(SUB_PROJ_DIR)))
SUB_TST_LIB  = $(shell echo $(SUB_PROJ_DIR) | sed 's/[0-9]*-/-l/g')

DEP_INC = $(PROJ_INC_DIR) $(SUB_INC_DIR)
DEP_LIB = $(PROJ_LIB_DIR) $(SUB_LIB_DIR) # $(SUB_TST_LIB)

# Tests
SUB_TST_INC_DIR = $(addprefix -I$(BASE_DIR)/,$(addsuffix /$(TST_DIR)/$(INC_DIR), $(SUB_PROJ_DIR)))
SUB_TST_LIB_DIR  = $(addprefix -L$(BASE_DIR)/,$(addsuffix /$(BUILD_DIR), $(SUB_PROJ_DIR)))


# CC flags and libs
CFLAGS 		  = -fPIC -Wall -Wextra -g -O0
LDFLAGS 	  = -shared
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS 	  = -lcheck -lm -lpthread -lrt
COV_LIBS 	  = -lgcov -coverage
LIBS   		  =

# Source files and object files
SRC_FILES  = $(shell find $(SRC_DIR) -name '*.c')
TST_FILES  = $(shell find $(TST_DIR) -name '*.c')
POBJ_FILES = $(addprefix $(BUILD_DIR)/,$(patsubst %.c,%.o,$(notdir $(SRC_FILES))))
LOBJ_FILES = $(addprefix $(BUILD_DIR)/,$(filter-out main.o, $(patsubst %.c,%.o,$(notdir $(SRC_FILES)))))
TOBJ_FILES = $(addprefix $(BUILD_DIR)/,$(patsubst %.c,%.o,$(notdir $(TST_FILES))))

SILENT	:=@
EC		= $(SILENT) echo

# Binary name
BIN = $(shell echo $(basename `pwd`) | cut -d'-' -f 2)
BIN_LIB	 = lib$(BIN).so
BIN_TEST = $(BIN)-test
CVG_FILE = $(BIN)-coverage_report.html

.PHONY: _start build run all test lib coverage valgrind clean

_start: build

run:
	$(SILENT) LD_LIBRARY_PATH=$(shell echo $(addprefix $(BASE_DIR)/,$(addsuffix /$(BUILD_DIR), $(SUB_PROJ_DIR))) | sed 's/ /\:/g') $(BUILD_DIR)/$(BIN)
