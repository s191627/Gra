#include "Help.h"


Help::Help(float width, float height)
{
	if (!font.loadFromFile("bemock/Bemock.ttf"))
	{
		cout << "No font is here";
	}

	
		HelpMenu[0].setFillColor(sf::Color(22, 71, 169));
		HelpMenu[0].setFont(font);
		HelpMenu[0].setString("1.Goal of the game:");
		HelpMenu[0].setCharacterSize(70);
		HelpMenu[0].setPosition((width / 2) - 337, 90);

		HelpMenu[1].setFillColor(sf::Color(176, 88, 0));
		HelpMenu[1].setFont(font);
		HelpMenu[1].setString("To brake all the blocks");
		HelpMenu[1].setCharacterSize(45);
		HelpMenu[1].setPosition((width / 2)-285, 180);

		HelpMenu[2].setFillColor(sf::Color(22, 71, 169));
		HelpMenu[2].setFont(font);
		HelpMenu[2].setString("2.How to play?");
		HelpMenu[2].setCharacterSize(70);
		HelpMenu[2].setPosition((width / 2) - 280, 300);

		HelpMenu[3].setFillColor(sf::Color(176, 88, 0));
		HelpMenu[3].setFont(font);
		HelpMenu[3].setString("Move the palette by arrows");
		HelpMenu[3].setCharacterSize(45);
		HelpMenu[3].setPosition((width / 2) - 325, 400);

	
	 
}

void Help::draw(RenderWindow& window)
{
	for (int i = 0; i < Lines; i++) 
	{
		window.draw(HelpMenu[i]);
	}
}


