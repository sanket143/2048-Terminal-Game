#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

// Compile with -lncurses

int main(){
  initscr();
  while(true){
    mvprintw(0, 0, "%s\n%s", "Sanket", "Hello World");
    refresh();
    sleep(1);
  }
  endwin();
  return 0;
}
