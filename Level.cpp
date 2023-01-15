#include "Level.h"



Level::Level(float width, float height)
{


	if (!font.loadFromFile("bemock/Bemock.ttf"))
	{
		cout << "No font is here";
	}


	for (int i = 0; i <= 3; i++)
	{
		LevelMenu[i].setFillColor(Color::White);
		LevelMenu[i].setFont(font);
		LevelMenu[i].setString(Buttons[i]);
		LevelMenu[i].setCharacterSize(70);
		LevelMenu[i].setPosition(67, 90 + offsetButtons * i);
	}

	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color(22, 71, 169));
	text.setString("NONE");
	text.setPosition(240.f, 10.f);

}



void Level::updateText(int lefel)
{
	stringstream ss;
	switch (lefel)
	{
	case(1):
		ss << "Level : Easy";
		break;
	case(2):
		ss << "Level : Medium";
		break;
	case(3):
		ss << "Level : Hard";
		break;
	}
	text.setString(ss.str());
}



void Level::update(int LVL)
{
	updateText(LVL);
}

void Level::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_lvl_menu; i++)
	{
		window.draw(LevelMenu[i]);
		window.draw(text);
	}
}


//void menu::draw(renderwindow& window)
//{
//	window.draw(title);
//
//	for (int i = 0; i < max_main_menu; i++)
//	{
//		window.draw(mainmenu[i]);
//	}
//}





