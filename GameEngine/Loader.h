#pragma once
#include "OpenGL.h"
#include "RawModel.h"

#include <vector>

using namespace std;

class Loader
{
private:
	vector<GLuint> vaos;
	vector<GLuint> vbos;

	int createVAO();
	void storeDataInAttributeList(int attributeNumber, vector<float> data);
	void unbindVAO();
public:
	Loader();
	~Loader();

	RawModel loadToVAO(vector<float> positions);
	void cleanUP();
};

