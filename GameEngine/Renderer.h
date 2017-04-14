#pragma once
#include "OpenGL.h"
#include "RawModel.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void prepare();
	void render(RawModel model);
};

