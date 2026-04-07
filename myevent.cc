#include "myevent.h"
#include "graphic_gui.h"
#include <cairomm/context.h>
#include <gtkmm/label.h>
#include <iostream>

constexpr int area_side(500);

MyEvent::MyEvent():
	m_Main_Box(Gtk::Orientation::HORIZONTAL, 0),
	m_Panel_Box(Gtk::Orientation::VERTICAL, 2),
	m_Buttons_Box(Gtk::Orientation::VERTICAL, 2),
	m_Panel_Frame("General"),
	m_Button_Draw("Draw"),
	m_Button_Clear("Clear"),
	draw(true)
{
	// init layout
	set_title("Exercice 1.1");
	set_child(m_Main_Box);

	m_Main_Box.append(m_Panel_Box);
	m_Main_Box.append(m_Area);
	
	m_Panel_Box.append(m_Panel_Frame);
	m_Panel_Frame.set_child(m_Buttons_Box);
	m_Buttons_Box.append(m_Button_Draw);
	m_Buttons_Box.append(m_Button_Clear);
	
	// init buttons signal handlers
	m_Button_Clear.signal_clicked().connect(
		sigc::mem_fun(*this, &MyEvent::on_button_clicked_clear));
		
    m_Button_Draw.signal_clicked().connect(
		sigc::mem_fun(*this, &MyEvent::on_button_clicked_draw));
		
	// init drawing sub-window parameters
	m_Area.set_content_width(area_side);
	m_Area.set_content_height(area_side);
	m_Area.set_expand();
	m_Area.set_draw_func(sigc::mem_fun(*this, &MyEvent::on_draw));

}

void MyEvent::on_button_clicked_clear()
{
	std::cout << "Drawing cancelled" << std::endl;
	draw = false;
	m_Area.queue_draw();
}

void MyEvent::on_button_clicked_draw()
{
	std::cout << "Drawing activated" << std::endl;
	draw = true;
	m_Area.queue_draw();
}

void MyEvent::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
	if(draw)
	{
		graphic_set_context(cr);
      // coordinates for the center of the GTKmm window
      int xc, yc;
      xc = width / 2;
      yc = height / 2;
      graphic_draw_shape(width, height,xc,yc);
	}
	else
	{
		std::cout << "Nothing to draw !" << std::endl;
	}
}