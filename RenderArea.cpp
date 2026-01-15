#include "RenderArea.hpp"
#include "cairomm/context.h"
#include "cairomm/refptr.h"
#include <cmath>

RenderArea::RenderArea() {
    set_draw_func(sigc::mem_fun(*this, &RenderArea::on_draw));
}

void RenderArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
    cr->set_source_rgba(0.1, 0.6, 0.9, 1.0);

    double x = width / 2.0;
    double y = height / 2.0;

    double radius = 3.0;

    cr->arc(x, y, radius, 0.0, 2.0 * M_PI);
    cr->fill();
}
