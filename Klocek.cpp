#include "Klocek.h"

Klocek::Klocek(float mX, float mY)
{
    shape.setPosition(mX, mY +10);

    shape.setSize({ x_size, y_size });

    shape.setFillColor(sf::Color(126, 212, 243));

    shape.setOrigin(x_size/ 2.f, y_size/ 2.f);
}

void Klocek::render(RenderTarget& target)
{
    target.draw(shape);
}


