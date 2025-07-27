#ifndef OBJECT_DRAWER_HPP
#define OBJECT_DRAWER_HPP

#include <traffic_state.hpp>
#include "imgui.h"

class ObjectDrawer {
    public:
        void draw(const Object &obj);

        ObjectDrawer(int width, int height) : window_width(width), window_height(height) {};

    private:
        int window_width;
        int window_height;

        ImVec2 translate_coords(const Vector2 &coords);
};

#endif