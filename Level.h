#pragma once
#include "Gra.h"
#include"Help.h"
#include"Menu.h"
#include"Exit.h"

#define Max_lvl_menu 4


class Level
{
private:

	int level = 1;
	Font font;
	Text text;
	Text LevelMenu[Max_lvl_menu];

	const char* Buttons[4] = { "Choose level", "1. Easy", "2. Medium", "3. Hard" };
	const int offsetButtons = 100;

public:
	Level(float width, float heigh);
	void updateText(int lefel);

	void update(int LVL);
	void draw(RenderWindow& window);


};

