#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;

#define Max_exit_menu 2

class Exit
{
private:
	int ExitSelected;
	Font font;
	Text ExitMenu[Max_exit_menu];
	const char* Buttons[2] = { "Of course No!", "Unfortunately Yes" };
	const int offsetButtons = 100;

	Text Title;

public:
	Exit(float width, float height);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();


	int ExitMenuPressed()
	{
		return ExitSelected;
	}
	int ReturnMenuSelected();
};

