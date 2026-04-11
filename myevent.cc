#include "myevent.h"

constexpr int area_side(750);

MyEvent::MyEvent(Game* game_ptr):
    m_Main_Box(Gtk::Orientation::HORIZONTAL, 0),
    m_Panel_Box(Gtk::Orientation::VERTICAL, 2),
    m_Buttons_Box(Gtk::Orientation::VERTICAL, 2),
	m_Panel1_Frame(),
	m_Panel2_Frame("infos:"),

    m_Button_Exit("Exit"),
    m_Button_Open("Open"),
    m_Button_Save("Save"),

    m_Grid(),
	m_lbl_sc_ti("score:"),
	m_lbl_sc_da("0"),
	m_lbl_li_ti("lives:"),
	m_lbl_li_da("0"),
	m_lbl_br_ti("bricks:"),
	m_lbl_br_da("0"),
	m_lbl_ba_ti("balls:"),
	m_lbl_ba_da("0"),
    game_graph(game_ptr)
{
	// init layout
	set_title("Brick Breaker");
	set_child(m_Main_Box);

	m_Main_Box.append(m_Panel_Box);
	m_Main_Box.append(m_Area);
	m_Panel1_Frame.set_child(m_Buttons_Box);
	m_Panel_Box.append(m_Panel1_Frame);
	m_Buttons_Box.append(m_Button_Exit);
	m_Buttons_Box.append(m_Button_Open);
	m_Buttons_Box.append(m_Button_Save);

	m_Panel2_Frame.set_child(m_Grid);
	m_Panel_Box.append(m_Panel2_Frame);

	set_grid();
	update_grid();
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
	m_Area.set_draw_func(sigc::mem_fun(game_graph, &Graphic::on_draw));

}

void MyEvent::clear(){

	game_graph.draw = false;
	m_Area.queue_draw();
}

void MyEvent::set_grid(){

	m_Grid.set_column_spacing(20);
	//m_Grid.set_margin_start(15);
	m_Grid.set_margin_end(5);

	m_Grid.attach(m_lbl_sc_ti,0,0);
	m_Grid.attach(m_lbl_sc_da,1,0);
	m_Grid.attach(m_lbl_li_ti,0,1);
	m_Grid.attach(m_lbl_li_da,1,1);
	m_Grid.attach(m_lbl_br_ti,0,2);
	m_Grid.attach(m_lbl_br_da,1,2);
	m_Grid.attach(m_lbl_ba_ti,0,3);
	m_Grid.attach(m_lbl_ba_da,1,3);

	m_lbl_sc_da.set_hexpand(true);
	m_lbl_sc_da.set_halign(Gtk::Align::END);
	m_lbl_li_da.set_halign(Gtk::Align::END);
	m_lbl_br_da.set_halign(Gtk::Align::END);
	m_lbl_ba_da.set_halign(Gtk::Align::END);
}

void MyEvent::update_grid(){

	m_lbl_sc_da.set_text(game_graph.get_score_str());
	m_lbl_li_da.set_text(game_graph.get_lives_str());
	m_lbl_br_da.set_text(game_graph.get_nb_bricks_str());
	m_lbl_ba_da.set_text(game_graph.get_nb_balls_str());
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

void MyEvent::on_file_dialog_response(int response_id, Gtk::FileChooserDialog* dialog){

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


