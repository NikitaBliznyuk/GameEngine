#pragma once
#include <vector>

using namespace std;

class Converter
{
public:
	template<typename T>
	static T* convert(vector<T> data);
};

template<typename T>
inline T * Converter::convert(vector<T> data)
{
	T* convData = new T[data.size()];
	for (int i = 0; i < data.size(); i++)
	{
		convData[i] = data.at(i);
	}
	return convData;
}
