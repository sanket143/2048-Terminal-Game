#include <bits/stdc++.h>
using namespace std;
#ifndef BOARD_H
#define BOARD_H

namespace gb{

  const int size = 4;
  bool flag = false;

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
      
        vector <int> available;

        for(int row = 0; row < 4; row++){
          for(int col = 0; col < 4; col++){
            if(tiles[row][col] == 0){
              available.push_back(row*4+col);
            }
          }
        }
        
        if(available.size()==0){
          printf("Game Over\n");
          exit(0);
        }
        int random_empty_tile = available[(int)(rand() % (int)available.size())];
        tiles[random_empty_tile/4][random_empty_tile%4] = 2;
          
      }

      bool shift(std::string direction){
        int non_zero;
        bool changed = false;
        if(direction == "R"){
          for(int row = 0; row < 4; row++){
            non_zero = 3;
            for(int col = 3; col >= 0; col--){
              if(tiles[row][col] != 0){
                if(col != non_zero){
                  tiles[row][non_zero] = tiles[row][col];
                  tiles[row][col] = 0;
                  changed = true;
                }
                non_zero -= 1;
              }
            }
          }
        }
        else if(direction == "D"){
          for(int col = 0; col < 4; col++){
            non_zero = 3;
            for(int row = 3; row >= 0; row--){
              if(tiles[row][col] != 0){
                if(row != non_zero){
                  tiles[non_zero][col] = tiles[row][col];
                  tiles[row][col] = 0;
                  changed = true;
                }
                non_zero -= 1;
              }
            }
          }
        }
        else if(direction == "L"){
          for(int row = 0; row < 4; row++){
            non_zero = 0;
            for(int col = 0; col < 4; col++){
              if(tiles[row][col] != 0){
                if(col != non_zero){
                  tiles[row][non_zero] = tiles[row][col];
                  tiles[row][col] = 0;
                  changed = true;
                }
                non_zero += 1;
              }
            }
          }
        }
        else if(direction == "U"){
          for(int col = 0; col < 4; col++){
            non_zero = 0;
            for(int row = 0; row < 4; row++){
              if(tiles[row][col] != 0){
                if(row != non_zero){
                  tiles[non_zero][col] = tiles[row][col];
                  tiles[row][col] = 0;
                  changed = true;
                }
                non_zero += 1;
              }
            }
          }
        } else {
          std::cout << "Invalid Direction." << std::endl;
        }
        return changed;
      }

      void move(std::string direction){
        flag |= shift(direction);
        if(direction == "R"){
          for(int row = 0; row < 4; row++){
            for(int col = 3; col > 0; col--){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row][col - 1]){
                tiles[row][col] += tiles[row][col - 1];
                tiles[row][col - 1] = 0;
                flag |= true;
                shift(direction);
              }
            }
          }
        }
        else if(direction == "D"){
          for(int col = 0; col < 4; col++){
            for(int row = 3; row > 0; row--){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row - 1][col]){
                tiles[row][col] += tiles[row-1][col];
                tiles[row - 1][col] = 0;
                flag |= true;
                shift(direction);
              }
            }
          } 
        }
        else if(direction == "L"){
          for(int row = 0; row < 4; row++){
            for(int col = 0; col < 3; col++){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row][col + 1]){
                tiles[row][col] += tiles[row][col + 1];
                tiles[row][col + 1] = 0;
                flag |= true;
                shift(direction);
              }
            }
          }
        }
        else if(direction == "U"){
          for(int col = 0; col < 4; col++){
            for(int row = 0; row < 3; row++){
              if(tiles[row][col] == 0){
                break;
              }

              if(tiles[row][col] == tiles[row + 1][col]){
                tiles[row][col] += tiles[row + 1][col];
                tiles[row + 1][col] = 0;
                flag |= true;
                shift(direction);
              }
            }
          }
        }
      }

      bool valid(std::string direction){
        std::string valid_directions[4] = {"R", "D", "L", "U"};
        for(int i = 0; i < 4; i++){
          if(direction == valid_directions[i]){
            return true;
          }
        }
        return false;
      }

      bool gameOver(){
        for(int row = 0;row<4;row++){
          for(int col = 0;col<4;col++){
            if(tiles[row][col] == 0) return false;
          }
        }
        bool a = true;
        for(int row = 0;row<3;row++){
          for(int col = 0;col<4;col++){
            if(tiles[row][col]==tiles[row+1][col]) a = false;
          }
        }

        for(int row = 0;row<4;row++){
          for(int col = 0;col<3;col++){
            if(tiles[row][col]==tiles[row][col+1]) a = false;
          }
        }

        if(tiles[3][3]==tiles[3][2] || tiles[3][3]==tiles[2][3]) a = false;

        return a;
      }

      void display(){
        flag = false;
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
