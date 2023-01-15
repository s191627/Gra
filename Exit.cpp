#include "Exit.h"


Exit::Exit(float width, float height)
{
	if (!font.loadFromFile("bemock/Bemock.ttf"))
	{
		cout << "No font is here";
	}


	Title.setFillColor(sf::Color(22, 71, 169));
	Title.setFont(font);
	Title.setString("You want to leave?");
	Title.setCharacterSize(50);
	Title.setPosition((width / 2) - 250, 90);

	for (int i = 0; i <= 1; i++)
	{
		ExitMenu[i].setFillColor(Color::White);
		ExitMenu[i].setFont(font);
		ExitMenu[i].setString(Buttons[i]);
		ExitMenu[i].setCharacterSize(40);
		ExitMenu[i].setPosition(70, 200 + offsetButtons * i);
	}
	ExitSelected = 0;
}
void Exit::draw(RenderWindow& window)
{
	window.draw(Title);

	for (int i = 0; i < Max_exit_menu; i++)
	{
		window.draw(ExitMenu[i]);
	}
}

void Exit::MoveUp()
{
	if (ExitSelected - 1 >= 0)
	{
		ExitMenu[ExitSelected].setFillColor(Color::White);


		ExitSelected--;
		if (ExitSelected == -1)
		{
			ExitSelected = 2;
		}
		ExitMenu[ExitSelected].setFillColor(sf::Color(176, 88, 0));
	}
}

void Exit::MoveDown()
{
	if (ExitSelected + 1 <= Max_exit_menu)
	{
		ExitMenu[ExitSelected].setFillColor(Color::White);
		ExitSelected++;
		if (ExitSelected == 2)
		{
			ExitSelected = 1;
		}
		ExitMenu[ExitSelected].setFillColor(sf::Color(176, 88, 0));
	}
}

int Exit::ReturnMenuSelected()
{
	return ExitSelected;
}
