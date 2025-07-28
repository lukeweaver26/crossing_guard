#ifndef OBJECT_DRAWER_HPP
#define OBJECT_DRAWER_HPP

#include <traffic_state.hpp>
#include "imgui.h"
#include <window_manager.hpp>

class ObjectDrawer {
    public:
        void draw(const Object &obj);

        ObjectDrawer() : window(WindowManager::getInstance().getWindow()){};
        
    private:
        GLFWwindow* window;

        ImVec2 translate_coords(const Vector2 &coords);
};

#endif