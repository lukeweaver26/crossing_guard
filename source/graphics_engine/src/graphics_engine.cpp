#include <GLFW/glfw3.h>
#include <graphics_engine.hpp>
#include <simulation_state.hpp>
#include <traffic_state.hpp>
#include <vector2.hpp>
#include <window_manager.hpp>

int GraphicsEngine::initialize() {
	GLFWwindow *window = WindowManager::getInstance().getWindow();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;

	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130");

	this->window = window;
	return 0;
}

int GraphicsEngine::step(const SimulationState &sim_state,
						 const TrafficState &traffic_state) {

	worldViewportSize = sim_state.worldViewportSize;

	for (size_t i = 0; i < traffic_state.renderables.size(); i++) {
		if (i == 0) {
			draw(traffic_state.renderables[i], IM_COL32(0, 0, 255, 255));
		} else {
			draw(traffic_state.renderables[i], IM_COL32(255, 0, 0, 255));
		}
	}

	return 0;
}

void GraphicsEngine::startFrame() {
	WindowManager::getInstance().pollEvents();

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void GraphicsEngine::endFrame() {
	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(window);
}

int GraphicsEngine::shutdown() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	return 0;
}

void GraphicsEngine::draw(const Renderable &obj, ImU32 color) {
	ImDrawList *draw_list = ImGui::GetBackgroundDrawList();

	ImVec2 center = translateCoordinatesToWindow(scaleToWindow(obj.position_m));
	ImVec2 half_size = scaleToWindow(obj.halfSize_m);

	float front_width = .1f * half_size.x;

	ImVec2 front_center = translateCoordinatesToWindow(scaleToWindow(
		{obj.position_m.x + half_size.x / 2 - front_width, obj.position_m.y}));
	(void)front_center;

	float angle_rad = obj.angle_rad;

	auto rotate = [](ImVec2 pt, float angle) -> ImVec2 {
		float s = sinf(-angle);
		float c = cosf(-angle);
		return ImVec2(pt.x * c - pt.y * s, pt.x * s + pt.y * c);
	};

	ImVec2 corners[4] = {{-half_size.x, -half_size.y},
						 {+half_size.x, -half_size.y},
						 {+half_size.x, +half_size.y},
						 {-half_size.x, +half_size.y}};

	for (int i = 0; i < 4; i++) {
		corners[i] = rotate(corners[i], angle_rad);
		corners[i].x += center.x;
		corners[i].y += center.y;
	}

	draw_list->AddConvexPolyFilled(corners, 4, color);
}

ImVec2 GraphicsEngine::translateCoordinatesToWindow(
	const ImVec2 &traffic_coordinates) {
	int window_width, window_height;
	glfwGetWindowSize(window, &window_width, &window_height);

	float half_width = static_cast<float>(window_width) / 2;
	float half_height = static_cast<float>(window_height) / 2;

	float x = traffic_coordinates.x + half_width;
	float y = -traffic_coordinates.y + half_height;

	return ImVec2(x, y);
}

ImVec2 GraphicsEngine::scaleToWindow(const Vector2 &size_m) {
	int window_width, window_height;
	glfwGetWindowSize(window, &window_width, &window_height);

	float x =
		size_m.x * (static_cast<float>(window_width) / worldViewportSize.x);
	float y =
		size_m.y * (static_cast<float>(window_height) / worldViewportSize.y);

	return ImVec2(x, y);
}