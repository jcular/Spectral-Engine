#pragma once

class GLFWwindow;

namespace sp {
	class SpWindow {
	public:
		SpWindow(int const width, int const height);

	public:
		void update() const;
		bool const initializedSuccessfuly() const;
		bool const shouldClose() const;

	private:
		int width;
		int height;
		bool initialized;
		GLFWwindow * concreteWindow = nullptr;
	};
}
