// generated by Fast Light User Interface Designer (fluid) version 1.0302

#ifndef btreegui_h
#define btreegui_h
#include <FL/Fl.H>
#include <fstream>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

class LinkedListStack : public Fl_Double_Window {
public:
  LinkedListStack(int x, int y, int w, int h, const char* t);
  void draw();
};
extern LinkedListStack *dw;
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#endif