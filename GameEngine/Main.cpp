#include <iostream>

#include "Display.h"

using namespace std;

int main()
{
	Display display(1280, 720);
	int displayInitializationState = display.initialize();

	if (displayInitializationState != 0)
	{
		cout << "Error: " << displayInitializationState << endl;
	}

	do
	{
		// code here
	} while (!display.update());

	display.close();

	cout << "Thank you!" << endl;
	system("pause");

	return 0;
}