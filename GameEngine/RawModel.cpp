#include "RawModel.h"

RawModel::RawModel(int vaoID, int vertexCount)
{
	this->vaoID = vaoID;
	this->vertexCount = vertexCount;
}

RawModel::~RawModel()
{
}

int RawModel::getVaoID()
{
	return vaoID;
}

int RawModel::getVertexCount()
{
	return vertexCount;
}
