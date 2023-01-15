#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("bemock/Bemock.ttf"))
	{
		cout << "No font is here";
	}
	


	Title.setFillColor(sf::Color(22, 71, 169));
	Title.setFont(font);
	Title.setString("ARKANOID ");
	Title.setCharacterSize(100);
	Title.setPosition((width / 2) -250, 70);

	for (int i = 0; i <= 2; i++)
	{
		MainMenu[i].setFillColor(Color::White);
		MainMenu[i].setFont(font);
		MainMenu[i].setString(Buttons[i]);
		MainMenu[i].setCharacterSize(70);
		MainMenu[i].setPosition(250, 200 + offsetButtons * i);
	}
	MainMenuSelected = 0;
	MainMenu[MainMenuSelected].setFillColor(sf::Color(176,88,0));
}
Menu::~Menu()
{

}
//Draw MainMenu
void Menu::draw(RenderWindow& window)
{
	window.draw(Title);

	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(MainMenu[i]);
	}
}
//MoveUp
void Menu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		MainMenu[MainMenuSelected].setFillColor(Color::White);


		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		MainMenu[MainMenuSelected].setFillColor(sf::Color(176, 88, 0));
	}
}
//MoveDown
void Menu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		MainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 3)
		{
			MainMenuSelected = 0;
		}
		MainMenu[MainMenuSelected].setFillColor(sf::Color(176, 88, 0));
	}
}

