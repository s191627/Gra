#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>

#define Lines 4

using namespace std;
using namespace sf;
class Help
{

private:
	
	int MainMenuSelected;
	Font font;
	Text HelpMenu[4];
	String string;

	const int offsetButtons = 100;


public:
	Help(float width, float height);

	void draw(RenderWindow& window);


	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	
};

