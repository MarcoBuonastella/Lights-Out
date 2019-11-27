#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"


using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Xwindow win;
  Grid g(&win);
  int moves = 0;
  int curr_size = 0;
  bool notDone = true;
  
  // You will need to make changes this code.

  while (notDone) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      g.init(n);
      curr_size = n;
    }
    else if (cmd == "init") {
      g.init(curr_size);
    }
    else if (cmd == "game") {
      cin >> moves;
      if (moves == 1){
        cout<<moves<<" move left"<<endl;
      }
      else{
        cout<<moves<<" moves left"<<endl;
      }
    }
    else if (cmd == "switch") {
      int r = 0, c = 0;
      cin >> r >> c;
      g.toggle(r,c);
      cout << g;
      moves--;
      if (moves == 1){
        cout << "1 moves left"<<endl;
      }
      else{
        cout <<moves<<" moves left"<<endl;
      }
      if (g.isWon()){
        cout <<"Won"<<endl;
        notDone = false;
        break;
      }
      if (moves == 0){
        cout<<"Lost"<<endl;
        notDone = false;
        break;
      }
    }
  }
}
