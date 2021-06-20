# -*- Makefile -*-
# Project makefile
# Author: Charly Batista
# Date: 2021-06-04

include ../config.mk

build: directories $(BIN)
	$(EC) "Done, enjoy your binary files :D"

all: build lib run coverage

directories:
	$(EC) "Creating directories $(BUILD_DIR)"
	$(SILENT) $(MKDIR) $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(EC) "PROJ_INC_DIR: $(PROJ_INC_DIR)"
	$(EC) "Compiling project file '$<' to create '$@'"
	$(SILENT) $(CC) -c -o $@ $< $(CFLAGS) $(DEP_INC)

$(BIN): $(POBJ_FILES)
	$(EC) "POBJ_FILES: $(POBJ_FILES)"
	$(EC) "Linking the object files ($^) to build '$@' executable file"
	$(SILENT) $(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS) $(LIBS) $(DEP_LIB) -llinked_list

coverage: $(CVG_FILE)

$(CVG_FILE): test
	$(EC) "Building coverage file $(BUILD_DIR)/$(CVG_FILE)"
	$(SILENT) $(GCOV) $(GCONV_FLAGS) -o $(BUILD_DIR)/$(CVG_FILE)

clean:
	$(SILENT) rm -Rf $(BUILD_DIR)
