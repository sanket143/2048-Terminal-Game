#include <iostream>

#ifndef BOARD_H
#define BOARD_H

namespace gb{

  const int size = 4;

  class Board{
    int tiles[size][size] = {};
    int score;

    public:
      Board(){
        score = 0;
        add_tile();
        add_tile();
      }

      void add_tile(){
        while(true){
          srand(time(0));
          int row = rand() % 4;
          int col = rand() % 4;
          if(tiles[row][col] == 0){
            tiles[row][col] = 2;
            break;
          }
        }
      }

      void shift(std::string direction){
        int non_zero;
        if(direction == "right"){
          for(int row = 0; row < 4; row++){
            non_zero = 3;
            for(int col = 3; col >= 0; col--){
              if(tiles[row][col] != 0){
                if(col != non_zero){
                  tiles[row][non_zero] = tiles[row][col];
                  tiles[row][col] = 0;
                }
                non_zero -= 1;
              }
            }
          }
        }
        else if(direction == "down"){
          for(int col = 0; col < 4; col++){
            non_zero = 3;
            for(int row = 3; row >= 0; row--){
              if(tiles[row][col] != 0){
                if(row != non_zero){
                  tiles[non_zero][col] = tiles[row][col];
                  tiles[row][col] = 0;
                }
                non_zero -= 1;
              }
            }
          }
        }
        else if(direction == "left"){
          for(int row = 0; row < 4; row++){
            non_zero = 0;
            for(int col = 0; col < 4; col++){
              if(tiles[row][col] != 0){
                if(col != non_zero){
                  tiles[row][non_zero] = tiles[row][col];
                  tiles[row][col] = 0;
                }
                non_zero += 1;
              }
            }
          }
        }
        else if(direction == "up"){
          for(int col = 0; col < 4; col++){
            non_zero = 0;
            for(int row = 0; row < 4; row++){
              if(tiles[row][col] != 0){
                if(row != non_zero){
                  tiles[non_zero][col] = tiles[row][col];
                  tiles[row][col] = 0;
                }
                non_zero += 1;
              }
            }
          }
        } else {
          std::cout << "Invalid Direction." << std::endl;
        }
      }

      void move(std::string direction){
        shift(direction);
        if(direction == "right"){
          for(int row = 0; row < 4; row++){
            for(int col = 3; col > 0; col--){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row][col - 1]){
                tiles[row][col] += tiles[row][col - 1];
                tiles[row][col - 1] = 0;
                shift(direction);
              }
            }
          }
        }
        else if(direction == "down"){
          for(int col = 0; col < 4; col++){
            for(int row = 3; row > 0; row--){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row - 1][col]){
                tiles[row][col] += tiles[row-1][col];
                tiles[row - 1][col] = 0;
                shift(direction);
              }
            }
          } 
        }
        else if(direction == "left"){
          for(int row = 0; row < 4; row++){
            for(int col = 0; col < 3; col++){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row][col + 1]){
                tiles[row][col] += tiles[row][col + 1];
                tiles[row][col + 1] = 0;
                shift(direction);
              }
            }
          }
        }
        else if(direction == "up"){
          for(int col = 0; col < 4; col++){
            for(int row = 0; row < 3; row++){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row + 1][col]){
                tiles[row][col] += tiles[row + 1][col];
                tiles[row + 1][col] = 0;
                shift(direction);
              }
            }
          }
        }
      }
      void right(){
        shift("right");
        for(int row = 0; row < 4; row++){
          for(int col = 3; col > 0; col--){
            if(tiles[row][col] == 0){
              break;
            }

            if(tiles[row][col] == tiles[row][col - 1]){
              tiles[row][col] += tiles[row][col - 1];
              tiles[row][col - 1] = 0;

              shift("right");
            }
          }
        }
      }

      void display(){
        for(int row = 0; row < size; row++){
          for(int col = 0; col < size; col++){
            if(tiles[row][col] == 0){
              std::cout << " .  ";
            } else {
              if(tiles[row][col] < 10){
                std::cout << " " << tiles[row][col] << "  ";
              }
              else if(tiles[row][col] < 100){
                std::cout << " " << tiles[row][col] << " ";
              }
              else if(tiles[row][col] < 1000){
                std::cout << " " <<  tiles[row][col];
              } else {
                std::cout << tiles[row][col];
              }
            }
          }
          std::cout << std::endl;
        }
        std::cout << std::endl;
      }
  };
}

#endif
