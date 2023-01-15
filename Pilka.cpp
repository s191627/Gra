#include "Pilka.h"

Pilka::Pilka()
{

        shape.setRadius(promien);

        shape.setFillColor(sf::Color(255,125,255));

        shape.setOrigin(promien, promien);

        
}

void Pilka::update()
{
    shape.move(predkosc);
    
}

void Pilka::render(RenderTarget& target)
{
    target.draw(shape);
}

void Pilka::basicPosition(float x, float y)
{
    shape.setPosition(x,y);
}


