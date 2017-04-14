#include "Loader.h"

int Loader::createVAO()
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	vaos.push_back(vaoID);
	glBindVertexArray(vaoID);
	return vaoID;
}

void Loader::storeDataInAttributeList(int attributeNumber, vector<float> data)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	vbos.push_back(vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, data.size(), Converter::convert<float>(data), GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}

Loader::Loader()
{

}

Loader::~Loader()
{

}

RawModel Loader::loadToVAO(vector<float> positions)
{
	int vaoID = createVAO();
	storeDataInAttributeList(0, positions);
	unbindVAO();
	return RawModel(vaoID, positions.size() / 3);
}

void Loader::cleanUP()
{
	for (int i = 0; i < vaos.size(); i++)
	{
		glDeleteVertexArrays(1, &vaos[i]);
	}

	for (int i = 0; i < vbos.size(); i++)
	{
		glDeleteBuffers(1, &vbos[i]);
	}
}
