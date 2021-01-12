// generated by Fast Light User Interface Designer (fluid) version 1.0302

#include "btreefluid.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>

void CustomWindow::draw() {
    fl_draw("asdf", 1, 1);
}

CustomWindow::CustomWindow(int w, int h,const char* t) {
    Fl_Double_Window(w, h, t);
}

int main(int argc, char **argv) {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(1896, 993);
    w = o;
    { new Fl_Box(5, 2, 1900, 1000, "drawbox");
    } // Fl_Box* o
    o->end();
  } // Fl_Double_Window* o

  CustomWindow(500, 500, "asdf");
  w->show(argc, argv);
  return Fl::run();
}
