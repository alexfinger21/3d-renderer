#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <gtkmm.h>
#include <memory>
#include "RenderArea.hpp"

class Screen {

    public:
        class RenderWindow : public Gtk::Window {
            public:
                Screen* parent;
                std::unique_ptr<RenderArea> m_render_area;
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
