#include "observer.h"
#include "cell.h"
#include <iostream>
using namespace std;
Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
  isOn = true;
}

void Cell::toggle() {
  if (isOn){
    isOn = false;
  }
  else{
    isOn = true;
  }
  notifyAllObservers();
}
void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::attach(Observer *o) {
  observers.emplace_back(o);
}

void Cell::notify(Cell &) {
  toggle();
}

SubscriptionType Cell::subType() {
  return SubscriptionType::SwitchOnly;
}

void Cell::notifyAllObservers() {
  for (int i = 0; i < observers.size(); ++i){
    if (observers.at(i)->subType() == SubscriptionType::All){
      observers[i]->notify(*this);
    }
  }
}

void Cell::notifySwitchObservers() {
  for (int i = 0; i <observers.size(); ++i){
    if (observers.at(i)->subType() == SubscriptionType::SwitchOnly){
      observers.at(i)->notify(*this);
    }
  }
}
