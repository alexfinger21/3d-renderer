#include "RenderArea.hpp"
#include "Vector3.hpp"
#include "cairomm/context.h"
#include "cairomm/refptr.h"
#include <cmath>
#include "Screen.hpp"


const int pt_size = 8;
const int edge_size = 12;

Vector3 pts[pt_size] = {
    Vector3{-1, 1, 3},
    Vector3{1, 1, 3},
    Vector3{1, -1, 3},
    Vector3{-1, -1, 3},
    Vector3{-1, 1, 5},
    Vector3{1, 1, 5},
    Vector3{1, -1, 5},
    Vector3{-1, -1, 5},
};

std::pair<int, int> edges[edge_size] = {
    // front face
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 0},
    // back face 
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 4},
    // connecting the faces
    {0, 4},
    {1, 5},
    {2, 6},
    {3, 7},
};

Vector3 pivot = {0, 0, 4};

double theta = 0.0;

RenderArea::RenderArea() {
    set_draw_func(sigc::mem_fun(*this, &RenderArea::on_draw));
    add_tick_callback(sigc::mem_fun(*this, &RenderArea::on_tick));
}

bool RenderArea::update_animation() {
    theta += 0.01;

    queue_draw();

    return true;
}

double rotateX(Vector3& vec, Vector3& pivot, double angle) {
    double c = cos(theta);
    double s = sin(theta);

    double d_x = (vec.x - pivot.x); 
    double d_z = (vec.z - pivot.z); 

    return pivot.x + (d_x*c - d_z*s); 
}

double rotateZ(Vector3& vec, Vector3& pivot, double angle) {
    double c = cos(theta);
    double s = sin(theta);

    double d_x = (vec.x - pivot.x); 
    double d_z = (vec.z - pivot.z); 

    return pivot.z + (d_x*s + d_z*c); 
}

double rotation_speed = 0.5; 
double last_t = 0.0;

bool RenderArea::on_tick(const Glib::RefPtr<Gdk::FrameClock>& frame_clock) {
    double t = frame_clock->get_frame_time() / 1000000.0; 
    
    if (last_t > 0) {
        double dt = t - last_t;
        theta += rotation_speed * dt; 
        std::cout << "FPS: " << (1.0/dt) << std::endl;
    }
    
    last_t = t;
    queue_draw();
    return true;
}

void RenderArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
    double s_x = this->screen->s_x * 1.0;
    double s_y = this->screen->s_y * 1.0;
    double scale = fmin(s_x, s_y)/2;

    double radius = 2.0;

    cr->set_source_rgba(0.1, 0.6, 0.9, 1.0);

    Vector3 rot_pts[pt_size];

    for (int i = 0; i<pt_size; ++i) {
        Vector3 pt = pts[i];
        Vector3 next_pt = pts[(i+1)%pt_size];

        double rotX = rotateX(pt, pivot, theta);
        double rotZ = rotateZ(pt, pivot, theta);

        double x = (s_x/2 + (rotX)*scale/rotZ);
        double y = (s_y/2 - pt.y*scale/rotZ);

        rot_pts[i] = Vector3{x, y, 0};

        cr->arc(x, y, radius, 0.0, 2.0 * M_PI);
        cr->fill();
    }

    cr->set_line_width(radius*2);
    for (int i = 0; i<edge_size; ++i) {
        Vector3 vec0 = rot_pts[edges[i].first];
        Vector3 vec1 = rot_pts[edges[i].second];

        cr->move_to(vec0.x, vec0.y);
        cr->line_to(vec1.x, vec1.y);
    }
    cr->stroke();
}
