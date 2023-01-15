#include "Paletka.h"

Paletka::Paletka()
{
    shape.setFillColor(sf::Color(115, 61, 6));
    shape.setOrigin(szerokosc_paletki / 2.f, wysokosc_paletki / 2.f);
    shape.setSize({ szerokosc_paletki , wysokosc_paletki });
}

void Paletka::basicPosition(float x, float y)
{
    shape.setPosition(x, y);
}

void Paletka::update(RenderTarget& target)
{
    
   
    shape.move(szybkosc);

    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)

        szybkosc.x = -szybkosc_paletki;

    else if (Keyboard::isKeyPressed(Keyboard::Key::Right) &&

        right() < target.getSize().x)

        szybkosc.x = szybkosc_paletki;

    else

        szybkosc.x = 0;
}

void Paletka::render(RenderTarget& target)
{
    target.draw(shape);
}

void Paletka::setpaletkaSize(float x)
{
    szerokosc_paletki = x;
    shape.setSize({ szerokosc_paletki , wysokosc_paletki });
    shape.setOrigin(szerokosc_paletki / 2.f, wysokosc_paletki / 2.f);
}
