#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(int n):gridSize{n}{
  theDisplay.resize(n);
  for (int i = 0; i < n; ++i){
    theDisplay[i].resize(n);
  }
}

void TextDisplay::notify(Cell &c) {
  if(c.getState() == true){
  theDisplay[c.getRow()][c.getCol()] = 'X';
  }
  else{
    theDisplay[c.getRow()][c.getCol()] = '_';
  }
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for(int i = 0; i < td.gridSize; ++i){
    for (int j = 0; j <td.gridSize; ++j){
      out << td.theDisplay[i][j];
    }
    out<<endl;
  }
  return out;
}
