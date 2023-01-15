#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;

#define Max_main_menu 3

class Menu
{

private:
	int MainMenuSelected;
	Font font;
	Text MainMenu[Max_main_menu];
	const char* Buttons[4] = { "Play", "Level", "Exit" };
	const int offsetButtons = 100;

	Text Title;


public:
	Menu(float width, float height);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();


	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~Menu();



};

