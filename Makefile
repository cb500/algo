# -*- Makefile -*-
# Project makefile
# Author: Charly Batista
# Date: 2021-06-04

include config.mk

.PHONY: build all test lib coverage valgrind clean

build:
	@echo "BASE_DIR (BASE): $(BASE_DIR)"
	@echo "SUB_INC_DIR (BASE): $(SUB_INC_DIR)"