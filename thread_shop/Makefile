CC := gcc
DEBUG := 
CFLAGS := -c
LDFLAGS := -lpthread

BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := build
HDR_DIR := headers

BIN := thread_shop
OBJ := tracker.o $(OBJ_DIR)/client.o $(OBJ_DIR)/$(BIN).o 
SRC := tracker.c $(SRC_DIR)/client.c $(SRC_DIR)/$(BIN).c 

.PHONY: all debug create_dir clean

all: create_dir $(BIN_DIR)/$(BIN)

create_dir:
	mkdir $(BIN_DIR)
	mkdir $(OBJ_DIR)

debug: DEBUG += -g 
debug: all

$(BIN_DIR)/$(BIN): $(OBJ_DIR)/$(OBJ) $(HDR_DIR)/$(BIN).h
	$(CC) $(DEBUG) $(OBJ_DIR)/$(OBJ) -o $(BIN_DIR)/$(BIN) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(DEBUG) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)