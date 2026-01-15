#include "Screen.hpp"
#include "RenderArea.hpp"
#include <gtkmm.h>

Screen::RenderWindow::RenderWindow(Screen* parent): parent(parent) {
    set_title("AR Render");
    set_default_size(parent->s_x, parent->s_y);

    this->m_render_area = std::make_unique<RenderArea>();
    this->set_child(*this->m_render_area);
}

void Screen::init_window() {
    this->window = std::make_unique<Screen::RenderWindow>(this);
}
