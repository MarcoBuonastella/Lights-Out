#include "window.h"
#include "cell.h"
#include "GraphicsDisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(Xwindow* w):w {w}{}

GraphicsDisplay::~GraphicsDisplay(){};

void GraphicsDisplay::notify(Cell & c){
  w->fillRectangle(c.getRow(), c.getCol(),10,10, 0);
  if(c.getState()){
    w->drawString(c.getRow(), c.getCol(), "XXXXXX");
  }
  else{
    w->drawString(c.getRow(), c.getCol(), "OOOOOO");
  }
}

SubscriptionType GraphicsDisplay::subType(){
  return SubscriptionType::All;
}

