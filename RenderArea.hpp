#ifndef RENDERAREA_h
#define RENDERAREA_h

#include "cairomm/context.h"
#include "cairomm/refptr.h"
#include "gtkmm/drawingarea.h"

class RenderArea : public Gtk::DrawingArea {
    public:
        RenderArea();
        virtual ~RenderArea();
    protected:
        void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};

#endif
