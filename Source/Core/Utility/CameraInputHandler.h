#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace sp {
	class CameraInputHandler {
	public:
		static void processCameraInput(GLFWwindow *window, float deltaTime);
		static void mouse_callback(GLFWwindow * window, double xpos, double ypos);

		static glm::vec3 worldUp;
		static bool firstMouse;
		static double lastX;
		static double lastY;
		static double yaw;
		static double pitch;
		static bool first;
	};
}
