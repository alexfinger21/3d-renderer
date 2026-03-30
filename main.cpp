#include <iostream>
#include <memory>
#include "RenderArea.hpp"
#include "Screen.hpp"
#include "Vector3.hpp"
#include <cmath>
#include "Object.hpp"
#include "matrix/Mat4.hpp"

int main(int argc, char* argv[]) {
    
    std::unique_ptr<Vector3> vec(new Vector3{.x=0, .y=5, .z=0});
    // vec->normalize();
    
    std::unique_ptr<Object> obj = std::make_unique<Object>(); 
    std::unique_ptr<Screen> scr;

    Mat4* matrix = new Mat4();
    matrix->rotation(M_PI, 'z');
    matrix->updateVector(*vec);

    std::cout << *matrix << std::endl;

    std::cout << *vec << std::endl;

    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("com.alex.ar_render");

    app->signal_activate().connect([&app, &scr]() {
        scr = std::make_unique<Screen>(600, 600);

        app->add_window(*scr->window);

        scr->window->present();
    });
    
    return app->run(argc, argv);
    //return 0;
}
