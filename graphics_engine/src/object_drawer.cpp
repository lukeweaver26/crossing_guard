#include <object_drawer.hpp>
#include "imgui.h"

void ObjectDrawer::draw(const Object &obj) {
   
  ImDrawList *draw_list = ImGui::GetBackgroundDrawList();

  ImVec2 center = translate_coords(obj.position);
  ImVec2 half_size(15, 7);
  float angle_rad = -atan2f(float(obj.direction.x), float(obj.direction.y)) + float(M_PI) / 2;

  auto rotate = [](ImVec2 pt, float angle) -> ImVec2 {
    float s = sinf(angle);
    float c = cosf(angle);
    return ImVec2(pt.x * c - pt.y * s, pt.x * s + pt.y * c);
  };

  ImVec2 corners[4] = {
    {-half_size.x, -half_size.y},
    {+half_size.x, -half_size.y},
    {+half_size.x, +half_size.y},
    {-half_size.x, +half_size.y}
  };

  for (int i = 0; i < 4; i++) {
    corners[i] = rotate(corners[i], angle_rad);
    corners[i].x += center.x;
    corners[i].y += center.y;
  }

  draw_list->AddConvexPolyFilled(corners, 4, IM_COL32(255,0,0,255));
}

ImVec2 ObjectDrawer::translate_coords(const Vector2 &traffic_plane) {
  float x = static_cast<float>(traffic_plane.x + 1) * 
                      (static_cast<float>(window_width) / 2);

  float y = static_cast<float>(traffic_plane.y + 1) *
                      (static_cast<float>(window_height) / 2);

  return ImVec2(x, y);
}