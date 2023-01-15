#include "Tlo.h"

Tlo::Tlo(float X, float Y)
{
	initTexture();
	initShape();
	shape.setPosition(X, Y);
}

void Tlo::initTexture()
{
	textura.loadFromFile("Zdjecia/Tlo.PNG");
}

void Tlo::initShape()
{
	shape.setScale(0.05f, 0.05f);
	shape.setTexture(textura);
}

void Tlo::update()
{
	shape.move(0.f, 0.1f);
}

void Tlo::render(RenderTarget& target)
{
	target.draw(shape);
}
