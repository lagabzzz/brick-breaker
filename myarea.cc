#include "myarea.h"
#include "graphic_gui.h"
#include <cairomm/context.h>
MyArea::MyArea(){
   set_draw_func(sigc::mem_fun(*this, &MyArea::on_draw));
}

MyArea::~MyArea(){}

void MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr,int width, int height) {

   graphic_set_context(cr);
   // coordinates for the center of the GTKmm window
   int xc, yc;
   xc = width / 2;
   yc = height / 2;
   graphic_draw_shape(width, height,xc,yc);
}