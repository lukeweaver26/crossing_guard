#include <object_drawer.hpp>

void ObjectDrawer::draw(const Object &obj) {
   
  ImDrawList *bg = ImGui::GetBackgroundDrawList();

  ImVec2 pos = translate_coords(obj.position);
  ImVec2 size(30, 15);
  bg->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y),
                    IM_COL32(255, 0, 0, 255));

}

ImVec2 ObjectDrawer::translate_coords(const Vector2 &traffic_plane) {
  float x = static_cast<float>(traffic_plane.x + 1) * 
                      (static_cast<float>(window_width) / 2);

  float y = static_cast<float>(traffic_plane.y + 1) *
                      (static_cast<float>(window_height) / 2);

  return ImVec2(x, y);
}