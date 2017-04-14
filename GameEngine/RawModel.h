#pragma once
class RawModel
{
private:
	int vaoID;
	int vertexCount;
public:
	RawModel(int vaoID, int vertexCount);
	~RawModel();

	int getVaoID();
	int getVertexCount();
};

