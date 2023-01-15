#pragma once
#include "Menu.h"
class Paletka
{
private:
    RectangleShape shape;
    
    float szerokosc_paletki{ 60.f }, wysokosc_paletki{ 15.f }, szybkosc_paletki{ 0.7f };
    
public:
    Paletka();
    void basicPosition(float x,float y);
    void update(RenderTarget& target);
    void render(RenderTarget& target);

    

    Vector2f szybkosc;

    float x() { return shape.getPosition().x; }

    float y() { return shape.getPosition().y; }

    float left() { return x() - shape.getSize().x / 2.f; }

    float right() { return x() + shape.getSize().x / 2.f; }

    float top() { return y() - shape.getSize().y / 2.f; }

    float bottom() { return y() + shape.getSize().y / 2.f; }

    void setpaletkaSize(float x);
};

