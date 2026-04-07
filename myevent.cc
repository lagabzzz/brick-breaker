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
	m_Panel_Frame(),
	m_Button_Exit("Exit"),
	m_Button_Open("Open"),
	m_Button_Save("Save"),
	draw(true)
{
	// init layout
	set_title("Brick Breaker");
	set_child(m_Main_Box);

	m_Main_Box.append(m_Panel_Box);
	m_Main_Box.append(m_Area);
	m_Panel_Frame.set_child(m_Buttons_Box);
	m_Panel_Box.append(m_Panel_Frame);
	m_Buttons_Box.append(m_Button_Exit);
	m_Buttons_Box.append(m_Button_Open);
	m_Buttons_Box.append(m_Button_Save);
	
	
	// init buttons signal handlers
	m_Button_Exit.signal_clicked().connect(
		sigc::mem_fun(*this, &MyEvent::on_button_clicked_exit));
		
   m_Button_Open.signal_clicked().connect(
		sigc::mem_fun(*this, &MyEvent::on_button_clicked_open));
		
	m_Button_Save.signal_clicked().connect(
		sigc::mem_fun(*this, &MyEvent::on_button_clicked_save));

	// init drawing sub-window parameters
	m_Area.set_content_width(area_side);
	m_Area.set_content_height(area_side);
	m_Area.set_expand();
	m_Area.set_draw_func(sigc::mem_fun(*this, &MyEvent::on_draw));

}

void MyEvent::clear(){

	draw = false;
	m_Area.queue_draw();
}

void MyEvent::on_button_clicked_exit(){

	exit(0);
}

void MyEvent::on_button_clicked_open(){

	clear();

	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		  Gtk::FileChooser::Action::OPEN);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
	sigc::mem_fun(*this, &MyEvent::on_file_dialog_response), dialog));
	
	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Open", Gtk::ResponseType::OK);
	
	//Add filters, so that only certain file types can be selected:
	
	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog->add_filter(filter_text);
	
	auto filter_cpp = Gtk::FileFilter::create();
	filter_cpp->set_name("C/C++ files");
	filter_cpp->add_mime_type("text/x-c");
	filter_cpp->add_mime_type("text/x-c++");
	filter_cpp->add_mime_type("text/x-c-header");
	dialog->add_filter(filter_cpp);
	
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);
	
	//Show the dialog and wait for a user response:
	dialog->show();
}

void MyEvent::on_button_clicked_save(){

	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		  Gtk::FileChooser::Action::SAVE);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
	sigc::mem_fun(*this, &MyEvent::on_file_dialog_response), dialog));
	
	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Save", Gtk::ResponseType::OK);
	
	//Add filters, so that only certain file types can be selected:
	
	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog->add_filter(filter_text);
	
	auto filter_cpp = Gtk::FileFilter::create();
	filter_cpp->set_name("C/C++ files");
	filter_cpp->add_mime_type("text/x-c");
	filter_cpp->add_mime_type("text/x-c++");
	filter_cpp->add_mime_type("text/x-c-header");
	dialog->add_filter(filter_cpp);
	
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);
	
	//Show the dialog and wait for a user response:
	dialog->show();
}

void MyEvent::on_file_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
	//Handle the response:
	switch (response_id)
	{
		case Gtk::ResponseType::OK:
		{
		    std::cout << "Open or Save clicked." << std::endl;
		
		    //Notice that this is a std::string, not a Glib::ustring.
		    filename = dialog->get_file()->get_path();
		    std::cout << "File selected: " <<  filename << std::endl;
		    break;
		}
		case Gtk::ResponseType::CANCEL:
		{
		    std::cout << "Cancel clicked." << std::endl;
		    break;
		}
		default:
		{
		    std::cout << "Unexpected button clicked." << std::endl;
		    break;
		}
	}
	delete dialog;
}


void MyEvent::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height){

	if(draw)
	{
		graphic_set_context(cr);
      // coordinates for the center of the GTKmm window
      int xc, yc;
      xc = width / 2;
      yc = height / 2;
      graphic_draw_shape(width, height,xc,yc);
	}
}