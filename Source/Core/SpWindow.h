#pragma once

class GLFWwindow;

namespace sp {
	class SpWindow {
	public:
		static void init(int const width, int const height);
		static SpWindow const * const getInstance();
		
	private:
		static SpWindow const * windowInstance;

	private:
		SpWindow(int const width, int const height);
		SpWindow(SpWindow const & window) = delete;

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
