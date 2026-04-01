#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <gtkmm.h>
#include <memory>
#include "RenderArea.hpp"
#include "glibmm/refptr.h"
#include "gdk/gdkkeysyms.h"
#include <gtkmm.h>
#include <iostream>

extern double theta;
extern double alpha;
extern double beta;

class Screen {

    public:
        class RenderWindow : public Gtk::Window {
            public:
                Screen* parent;

                std::unique_ptr<RenderArea> m_render_area;

                bool on_press(guint keyval, guint, Gdk::ModifierType state);

                RenderWindow(Screen* parent);
        };

        int s_x, s_y;

        std::unique_ptr<RenderWindow> window;

        Screen(int size_x, int size_y): 
            s_x(size_x),
            s_y(size_y)
        {
            init_window();
        };

        void init_window();

        Glib::RefPtr<Gtk::Application> returnApp();

};

#endif
