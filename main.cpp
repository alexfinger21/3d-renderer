#include <iostream>
#include <memory>
#include "Screen.hpp"
#include "Vector3.hpp"
#include "Object.hpp"

int main(int argc, char* argv[]) {
    
    std::unique_ptr<Vector3> vec(new Vector3{.x=0, .y=65, .z=0});
    vec->normalize();
    
    std::unique_ptr<Object> obj = std::make_unique<Object>(); 
    std::unique_ptr<Screen> scr;

    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("com.alex.ar_render");
    app->signal_activate().connect([&app, &scr]() {
        scr = std::make_unique<Screen>(200, 200);
        app->add_window(*scr->window);
        scr->window->present();
    });
    
    return app->run(argc, argv);
    //return 0;
}
