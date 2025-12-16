#include "Screen.hpp"
#include <iostream>
#include <gtkmm.h>

Screen::RenderWindow::RenderWindow(Screen* parent): parent(parent) {
    set_title("AR Render");
    set_default_size(parent->s_x, parent->s_y);
}

void Screen::init_window() {
    this->window = std::make_unique<Screen::RenderWindow>(this);
}
