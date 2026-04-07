#ifndef GTKMM_MY_EVENT_H
#define GTKMM_MY_EVENT_H

//#include <gtkmm/applicationwindow.h>
//#include <gtkmm/box.h>
//#include <gtkmm/button.h>
//#include <gtkmm/frame.h>
//#include <gtkmm/drawingarea.h>

#include <gtkmm.h>

class MyEvent : public Gtk::ApplicationWindow
{
public:
	MyEvent();

private:
	// GUI layout
	Gtk::Box m_Main_Box;
	Gtk::Box m_Panel_Box;
	Gtk::Box m_Buttons_Box;
	Gtk::Frame m_Panel_Frame;
	Gtk::Button m_Button_Exit;
	Gtk::Button m_Button_Open;
	Gtk::Button m_Button_Save;
	Gtk::DrawingArea m_Area;

	std::string filename;

	bool draw ; // current drawing state
	
	void clear();
	//Button Signal handlers:
	void on_button_clicked_exit();
	void on_button_clicked_open();
	void on_button_clicked_save();

	void on_file_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);

	// DrawingArea signal handler:
	void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};

#endif // GTKMM_MY_EVENT_H