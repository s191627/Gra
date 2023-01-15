#pragma once
#include"Menu.h"

class Pilka
{
private:

	CircleShape shape;

public:
	Pilka();
	void update();
	void render(RenderTarget& target);

	void basicPosition(float x, float y);

	float promien{ 10.f }, predkoscP{ 0.25f };

	Vector2f predkosc{ -predkoscP, -predkoscP };

	float x() { return shape.getPosition().x; }

	float y() { return shape.getPosition().y; }

	float left() { return x() - shape.getRadius(); }

	float right() { return x() + shape.getRadius(); }

	float top() { return y() - shape.getRadius(); }

	float bottom() { return y() + shape.getRadius(); }

	const FloatRect getBounds() const
	{
		return shape.getGlobalBounds();
	}
};

