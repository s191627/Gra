#pragma once

#include <SFML/Graphics.hpp>
#include<stdio.h>
#include <iostream>
#include <sstream>

#include <time.h>

#include <vector>
#include "Pilka.h"
#include "Paletka.h"
#include "Klocek.h"
#include "Ksiezyc.h"
#include "Level.h"



using namespace std;

using namespace sf;

class Gra
{
private:

	bool Endgame = false;

	int szerokosc_okna{ 800 };
	int wysokosc_okna{ 600 };

	int punkty = 0;
	int level = 1;

	float szerokosc_paletki = 40.f;

	int ilosc_puchatkow = 10;
	int ilosc_puchatkow_obecnie = 0;
	unsigned timer = 0;

	Text text;
	Font font;

	Paletka paletka;

	Pilka pilka;

	vector<Ksiezyc*> ksiezyc;

	vector<Klocek> klocki;

	int klockiX{ 11 }, klockiY{ 7 };
	float szerokosc_klocka{ 60.f }, wysokosc_klocka{ 20.f };

public:
	Gra();

	template <class T1, class T2>
	bool isIntersecting(T1& mA, T2& mB);

	void testCollision(Paletka& mPaletka, Pilka& mPilka);

	void getLevel(int LVL)
	{
		level = LVL;
	}

	void renderklocki();
	void updateklocki();

	void WallCollision(Pilka& pilka, RenderTarget& target);

	void update(RenderTarget& target);

	void updateKsiezyc(RenderTarget& target);

	void render(RenderTarget& target);
	
	const bool EndGame() const
	{
		return Endgame;
	}
	int Punkty()
	{
		return punkty;
	}

	//Text and Fonts

	void initFont();
	void initText();
	void updateText();
	void rendertext(RenderTarget& target);

	void setLevel(int poziom);


};


