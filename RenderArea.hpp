#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include "cairomm/context.h"
#include "cairomm/refptr.h"
#include "gtkmm/drawingarea.h"

class Screen;

class RenderArea : public Gtk::DrawingArea {
    public:
        RenderArea();
        Screen* screen;
        virtual ~RenderArea() {};
    protected:
        void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
        bool update_animation();
        bool on_tick(const Glib::RefPtr<Gdk::FrameClock>& frame_clock);
};

#endif
