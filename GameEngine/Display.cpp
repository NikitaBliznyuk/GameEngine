#include "Display.h"


Display::Display(int width, int height)
{
	this->width = width;
	this->height = height;
}

Display::~Display()
{

}

int Display::initialize()
{
	if (!glfwInit())
		return 1;

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	window = glfwCreateWindow(width, height, "Hello World!", NULL, NULL);
	if (window == NULL)
		return 2;

	const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	// Center the window
	glfwSetWindowPos(
		window,
		(vidmode->width - width) / 2,
		(vidmode->height - height) / 2
	);
	// Make the OpenGL context current
	glfwMakeContextCurrent(window);
	// Enable v-sync
	glfwSwapInterval(1);

	// Make the window visible
	glfwShowWindow(window);

	if (glewInit() != GLEW_OK)
		return -3;

	return 0;
}

bool Display::update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();

	return glfwWindowShouldClose(window);
}

void Display::close()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
