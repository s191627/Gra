#include "Ksiezyc.h"

Ksiezyc::Ksiezyc(float X, float Y)
{
	initTexture();
	initShape();
	shape.setPosition(X, Y);
}

void Ksiezyc::initTexture()
{
	textura.loadFromFile("Zdjecia/telewizor.PNG");
}

void Ksiezyc::initShape()
{
	shape.setScale(0.05f, 0.05f);
	shape.setTexture(textura);
}

void Ksiezyc::update()
{
	shape.move(0.f, 0.1f);
}

void Ksiezyc::render(RenderTarget& target)
{
	target.draw(shape);
}
