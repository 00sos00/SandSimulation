#include <iostream>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

class Game {
public:
	GLFWwindow* window = NULL;

	Game(int windowWidth, int windowHeight, const char* windowTitle, int major, int minor) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow* _window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);

		if (!_window) {
			std::cout << "Failed to create GLFW Window" << std::endl;
			glfwTerminate();
			abort();
		}

		glfwMakeContextCurrent(_window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
			abort();
		}

		window = _window;
	}
};