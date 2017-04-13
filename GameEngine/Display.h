#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Display
{
private:
	int width, height;
	GLFWwindow* window;

public:
	Display(int width, int height);
	~Display();

	int initialize();
	bool update();
	void close();
};

