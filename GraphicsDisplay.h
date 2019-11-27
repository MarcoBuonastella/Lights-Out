#ifndef Graphics_h
#define Graphics
#include "observer.h"
#include "window.h"
class Cell;

class GraphicsDisplay: public Observer{
  Xwindow* w;
  public:
    GraphicsDisplay(Xwindow* w);
   ~GraphicsDisplay();
    void notify(Cell &c) override;
    SubscriptionType subType() override;
    void setWindow(Xwindow* win);
};
#endif
