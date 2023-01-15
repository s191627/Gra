#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Gra.h"
#include"Help.h"
#include"Menu.h"
#include"Exit.h"


constexpr int szerokosc_okna{ 800 };

constexpr int wysokosc_okna{ 600 };

int poziom = 1;







int main()

{
	{
		srand(static_cast<unsigned>(time(0)));

		bool GamePlay = false;
		bool EKSIT = false;

		Gra Gra;
	

		RenderWindow MENU(VideoMode(800.f, 600.f), "Main Menu", Style::Close || Style::Titlebar);
		Menu mainMenu(MENU.getSize().x, MENU.getSize().y);

		//setBackground
		RectangleShape background;
		background.setSize(Vector2f(790.f, 590.f));
		background.setPosition(0,0);
		Texture Maintexture;
		Maintexture.loadFromFile("Zdjecia/telewizor.png");
		background.setTexture(&Maintexture);


		//tlo do gry
		RectangleShape Gbackground;
		Gbackground.setSize(Vector2f(790.f, 590.f));
		Gbackground.setPosition(0, 0);
		Texture Backtexture;
		Backtexture.loadFromFile("Zdjecia/tlog.png");
		Gbackground.setTexture(&Backtexture);


		while (MENU.isOpen())
		{
			Event event;
			while (MENU.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					MENU.close();
				}
				if (event.type == Event::KeyReleased)
					if (event.key.code == Keyboard::Up)
					{
						mainMenu.MoveUp();
						break;
					}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Play(VideoMode(800, 600), "game_name");
					RenderWindow OPTIONS(VideoMode(800, 600), "OPTIONS");

					Level level(OPTIONS.getSize().x, OPTIONS.getSize().y);

					int x = mainMenu.MainMenuPressed();

					if (x == 0)
					{
						Gra.getLevel(poziom);

						while (Play.isOpen())
						{
							Event aevent;
							
							


							while (Play.pollEvent(aevent))
							{

								if (Gra.EndGame())
									EKSIT = true;


								if (aevent.type == Event::Closed)
								{
									Play.close();
								}
								if (aevent.type == Event::KeyPressed)
								{

									//help

									if (aevent.key.code == Keyboard::F1)
									{
										RenderWindow HELP(VideoMode(800, 600), "Help", Style::Titlebar);
										Help help(HELP.getSize().x, HELP.getSize().y);

										while (HELP.isOpen())
										{
											while (HELP.pollEvent(aevent))
											{
												if (aevent.type == Event::KeyPressed)
												{
													if (aevent.key.code == Keyboard::F1)
													{
														HELP.close();
													}
												}
											}
											HELP.clear();
											HELP.draw(background);
											help.draw(HELP);
											HELP.display();
										}
									}

									//exit
									if (aevent.key.code == Keyboard::Escape)
									{
										RenderWindow EXIT(VideoMode(800, 600), "EXIT");
										Exit exitMenu(EXIT.getSize().x, EXIT.getSize().y);


										while (EXIT.isOpen())
										{



											while (EXIT.pollEvent(aevent))
											{
												if (aevent.type == Event::KeyPressed)
												{

													if (aevent.key.code == Keyboard::Up)
													{
														exitMenu.MoveUp();
													}

													if (aevent.key.code == Keyboard::Down)
													{
														exitMenu.MoveDown();
													}

													if (aevent.key.code == Keyboard::Return)
													{
														if (exitMenu.ReturnMenuSelected() == 1)
															EKSIT = true;

														if (exitMenu.ReturnMenuSelected() == 2)
															EKSIT = false;

												
														EXIT.close();

													}
													



												}
											}
											EXIT.clear();
											EXIT.draw(background);
											exitMenu.draw(EXIT);
											EXIT.display();


										}
										
										

									}


								}

							}
							if (!EKSIT)
							{
								OPTIONS.close();

								Play.clear();
								Gra.update(Play);

								Play.draw(Gbackground);
								Gra.render(Play);


								Play.display();

							}
							else
							{
								Play.close();
								
							}
								


						}

					}
					//poziom

					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();
									}
									if (aevent.key.code == Keyboard::Num1)
									{
										poziom = 1;
									}
									if (aevent.key.code == Keyboard::Num2)
									{
										poziom = 2;
									}
									if (aevent.key.code == Keyboard::Num3)
									{
										poziom = 3;
									}
								}
							}

							Play.close();
							OPTIONS.clear();

							level.update(poziom);
							OPTIONS.draw(background);
							level.draw(OPTIONS);
					

							OPTIONS.display();

						}
					}
					if (x == 2)
					{
						
						MENU.close();
						break;
						
					}
					
				}
			}
			MENU.clear();

			MENU.draw(background);
			mainMenu.draw(MENU);
		    MENU.display();
		}

	}
}



