SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./build/obj
BIN_DIR = ./build
DOC_DIR = ./docs

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))
DOXY_FILE = $(wildcard $(Doxyfile))

all: build_folders $(OBJ_FILES)
	@echo Building aplication
	@gcc $(OBJ_FILES) -o $(BIN_DIR)/app.out

doc: $(DOC_DIR)
	doxygen $(DOXY_FILE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling source file $(notdir $(basename $<))
	@gcc -c $< -I$(INC_DIR) -o $@

###############################################################################
# Creation of output folders
build_folders: $(BIN_DIR) $(LIB_DIR) $(OBJ_DIR) $(DOC_DIR) $(DPN_DIR) $(RST_DIR)

$(OUT_DIR):
	@echo Creating output root folder
	@mkdir $(OUT_DIR)

$(BIN_DIR): $(OUT_DIR)
	@echo Creating output binaries folder
	@mkdir $(BIN_DIR)

$(OBJ_DIR): $(OUT_DIR)
	@echo Creating output objects folder
	@mkdir $(OBJ_DIR)

$(DOC_DIR): $(OUT_DIR)
	@echo Creating output document folder
	@mkdir $(DOC_DIR)
