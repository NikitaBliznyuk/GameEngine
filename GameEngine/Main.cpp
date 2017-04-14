#include <iostream>

#include "Display.h"
#include "Loader.h"
#include "Renderer.h"

using namespace std;

int main()
{
	Display display(1280, 720);
	int displayInitializationState = display.initialize();
	if (displayInitializationState != 0)
	{
		cout << "Error: " << displayInitializationState << endl;
	}
	Loader loader;
	Renderer renderer;

	vector<float> vertices;
	vertices.push_back(-0.5f);	vertices.push_back(0.5f);	vertices.push_back(0.0f);
	vertices.push_back(-0.5f);	vertices.push_back(-0.5f);	vertices.push_back(0.0f);
	vertices.push_back(0.5f);	vertices.push_back(-0.5f);	vertices.push_back(0.0f);

	vertices.push_back(0.5f);	vertices.push_back(-0.5f);	vertices.push_back(0.0f);
	vertices.push_back(0.5f);	vertices.push_back(0.5f);	vertices.push_back(0.0f);
	vertices.push_back(-0.5f);	vertices.push_back(0.5f);	vertices.push_back(0.0f);

	RawModel model = loader.loadToVAO(vertices);

	do
	{
		renderer.prepare();
		renderer.render(model);
		//game logic code here
	} while (!display.update());

	loader.cleanUP();
	display.close();

	cout << "Thank you!" << endl;
	system("pause");

	return 0;
}