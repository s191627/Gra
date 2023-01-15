#pragma once
#include "Menu.h"

class Tlo
{
private:

	Sprite shape;
	Texture textura;


public:

	Tlo(float X, float Y);

	void initTexture();
	void initShape();

	void update();
	void render(RenderTarget& target);

	float getPosY()
	{
		return shape.getPosition().y;
	}


};


