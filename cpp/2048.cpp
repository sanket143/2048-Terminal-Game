#include <iostream>
#include "board.h"

int main() {
  gb::Board board;
  while(true) {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "2048 Terminal Game" << std::endl;
    std::cout << "Valid Directions: [R|D|L|U]" << std::endl;
    std::string input;

    board.display();

    std::cout << "Direction: ";
    std::cin >> input;

    if(!board.valid(input)) {
      continue;
    }
    std::cout << "Loading..." << std::endl;
    board.move(input);
    if(gb::flag)
    board.add_tile();
    board.display();
    if(board.gameOver()) {
      cout << "\n GAME OVER !!! \n";
      return 0;
    }
  }
}
