#include <iostream>
#include <vector>
#include "grid.h"
#include "textdisplay.h"
using namespace std;

Grid::Grid(Xwindow* w): w {w}{}

Grid::~Grid() {
  delete td;
  delete gd;
}


void Grid::clearGrid() {
  for(int i = 0; i < gridSize; ++i){
    for (int j = 0; j <gridSize; ++j){
      theGrid[i].erase(theGrid[j].begin() + j);
    }
   theGrid.erase(theGrid.begin() + i); 
  }
}

void Grid::checkWon(){ 
 for (int i = 0; i < gridSize; ++i){
   for (int j = 0; j < gridSize; ++j){
     if (theGrid[i][j].getState()){
       won = false;
     }
   }
 }
}

bool Grid::isWon() const{
  return won;
}

void Grid::init(int n) {
  if (theGrid.size() == 0){
    clearGrid();
    gridSize = n;
    won = true;
    theGrid.resize(n);
    for (int j = 0; j < n; ++j){
      theGrid[j].resize(n);
    }
    td = new TextDisplay{n};
    gd = new GraphicsDisplay{w};
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        theGrid[i][j].setCoords(i,j);
      }
    }
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        if ((i - 1) >= 0 ){
          theGrid[i][j].attach(&theGrid[i-1][j]);
        }
        if ((i + 1) < n){
          theGrid[i][j].attach(&theGrid[i+1][j]);
        }
        if ((j - 1) >= 0){
          theGrid[i][j].attach(&theGrid[i][j-1]);
        }
        if ((j + 1) < n ){
          theGrid[i][j].attach(&theGrid[i][j+1]);
        }
        theGrid[i][j].attach(td);
        theGrid[i][j].attach(gd);
      }
    }
  }
  else{
    while (true){
      int r = 0; int c = 0;
      cin >> r >> c;
      if (r == -1 && c == -1){
        break;
      }
      turnOn(r,c);
      theGrid[r][c].notifyAllObservers();
    }
    cout << *td;
  }
  for(int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      theGrid[i][j].notifyAllObservers();
    }
  }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].notifySwitchObservers();
  theGrid[r][c].toggle();
  Grid::checkWon();
}

ostream &operator<<(ostream &out, const Grid &g) {
  out << *g.td;
  return out;
}
