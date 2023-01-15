#pragma once
#include "Menu.h"

class Ksiezyc
{
private:

	Sprite shape;
	Texture textura;


public:

	Ksiezyc(float X, float Y);

	void initTexture();
	void initShape();

	void update();
	void render(RenderTarget& target);

	float getPosY()
	{
		return shape.getPosition().y;
	}


};

