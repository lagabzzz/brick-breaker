#ifndef GUI_H
#define GUI_H

#include <array>
#include <gtkmm.h>
#include "game.h"


enum Response
{
    CANCEL,
    OPEN_FILE,
    SAVE_FILE
};
enum Buttons
{
    EXIT,
    OPEN,
    SAVE,
    RESTART,
    START,
    STEP
};

class My_window : public Gtk::Window
{
public:

    My_window(std::string file_name = "");

private:

    Game game;
    std::string filename;
    bool loop_activated;
    Gtk::Box main_box, panel_box, command_box;
    Gtk::Grid info_grid;
    sigc::connection loop_conn;
    std::array<Gtk::Button, 6> buttons;
    Gtk::Frame info_frame;
    std::array<Gtk::Label, 4> info_text, info_value;
    Gtk::DrawingArea drawing;
    int m_width;
    int m_height;
    int m_side;

	
	
    void set_commands();

    void exit_clicked();
    void open_clicked();
    void save_clicked();
    void restart_clicked();
    void start_clicked();
    void step_clicked();

    void set_key_controller();
    bool key_pressed(guint keyval, guint keycode, Gdk::ModifierType state);

    void set_dialog(Gtk::FileChooserDialog *dialog);
    void dialog_response(int response, Gtk::FileChooserDialog *dialog);

    bool loop();

    void set_infos();
    void update_infos();

    void set_drawing();
    void on_draw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height);

    void set_mouse_controller();
    void on_drawing_left_click(int n_press, double x, double y);
    void on_drawing_move(double x, double y);
};

#endif