#pragma once
#include "Menu.h"
class Klocek
{
private:
    RectangleShape shape;
    float x_size = 60.f;
    float y_size = 20.f;
  
public:

    
    bool destroyed{ false };
    Klocek(float mX, float mY);

    void render(RenderTarget& target);


    float x() { return shape.getPosition().x; }

    float y() { return shape.getPosition().y; }

    float left() { return x() - shape.getSize().x / 2.f; }

    float right() { return x() + shape.getSize().x / 2.f; }

    float top() { return y() - shape.getSize().y / 2.f; }

    float bottom() { return y() + shape.getSize().y / 2.f; }
    
    const FloatRect getBounds() const
    {
        return shape.getGlobalBounds();
    }
};

