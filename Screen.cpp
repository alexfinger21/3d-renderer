#include "Screen.hpp"

Screen::RenderWindow::RenderWindow(Screen* parent): parent(parent) {
    set_title("AR Render");
    set_default_size(parent->s_x, parent->s_y);

    this->m_render_area = std::make_unique<RenderArea>();
    this->m_render_area->screen = this->parent;
    this->set_child(*this->m_render_area);
}

void Screen::init_window() {
    this->window = std::make_unique<Screen::RenderWindow>(this);

    Glib::RefPtr<Gtk::EventControllerKey> controller = Gtk::EventControllerKey::create();

    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this->window, &Screen::RenderWindow::on_press),
        false
    );
    
    this->window->add_controller(controller);
}

bool Screen::RenderWindow::on_press(guint keyval, guint, Gdk::ModifierType state) {
    std::cout << "GETTING PRESSES RN" << std::endl;
    std::cout << keyval << std::endl;
    std::cout << GDK_KEY_h << std::endl;

    if (keyval == GDK_KEY_J) {
        theta += 0.11;

        return true;
    }

    if (keyval == GDK_KEY_j) {
        theta -= 0.11;

        return true;
    }

    if (keyval == GDK_KEY_K) {
        alpha += 0.11;

        return true;
    }

    if (keyval == GDK_KEY_k) {
        alpha -= 0.11;

        return true;
    }

    if (keyval == GDK_KEY_L) {
        beta += 0.11;

        return true;
    }

    if (keyval == GDK_KEY_l) {
        beta -= 0.11;

        return true;
    }

    return false;
}
