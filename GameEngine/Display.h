#pragma once
#include "OpenGL.h"

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

