SRC_DIR=./src
MAIN_FILE=$(SRC_DIR)/2048.cpp
BOARD_H=$(SRC_DIR)/board.h

start: $(MAIN_FILE) $(BOARD_H)
	@g++ $(MAIN_FILE) -I $(SRC_DIR) -o start
	@echo "./start # To start the game"
