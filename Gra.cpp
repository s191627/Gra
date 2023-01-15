#include "Gra.h"

Gra::Gra()
{
    renderklocki();
    
    

    paletka.basicPosition(szerokosc_okna/2, wysokosc_okna - 50);
    pilka.basicPosition(rand() % szerokosc_okna, wysokosc_okna/2);
    initText();
    initFont();
}

void Gra::testCollision(Paletka& mPaletka, Pilka& mPilka)
{

    if (!isIntersecting(mPaletka, mPilka)) return;


    mPilka.predkosc.y = -pilka.predkoscP;


    if (mPilka.x() < mPaletka.x())

        mPilka.predkosc.x = -pilka.predkoscP;

    else

        mPilka.predkosc.x = pilka.predkoscP;
}


void Gra::renderklocki()
{
    for (int iX{ 0 }; iX < klockiX; ++iX)

        for (int iY{ 0 }; iY < klockiY; ++iY)

            klocki.emplace_back(

                (iX + 1) * (szerokosc_klocka + 3) + 22,

                (iY + 2) * (wysokosc_klocka + 3));

}
void Gra::updateklocki()
{
    unsigned counter_2 = 0;

    for (auto kloc : klocki)
    {
        if (pilka.getBounds().intersects(kloc.getBounds()))
        {
            float zderzenieLewe{ pilka.right() - kloc.left() };

            float zderzeniePrawe{ kloc.right() - pilka.left() };

            float zderzenieGora{ pilka.bottom() - kloc.top() };

            float zderzenieDol{ kloc.bottom() - pilka.top() };



            bool pilkaLewa(abs(zderzenieLewe) < abs(zderzeniePrawe));

            bool pilkaGora(abs(zderzenieGora) < abs(zderzenieDol));



            float minzderzenieX{ pilkaLewa ? zderzenieLewe : zderzeniePrawe };

            float minzderzenieY{ pilkaGora ? zderzenieGora : zderzenieDol };



            if (abs(minzderzenieX) < abs(minzderzenieY))

                pilka.predkosc.x = pilkaLewa ? pilka.predkoscP * (-1.0f) : pilka.predkoscP;

            else

                pilka.predkosc.y = pilkaGora ? pilka.predkoscP * (-1.0f) : pilka.predkoscP;
        }
      
            
           if (kloc.getBounds().intersects(pilka.getBounds()))
           {
           
       
               klocki.erase(klocki.begin() + counter_2);
               --counter_2;
               punkty += 1;
           }
           counter_2++;
            
    }
    
    

}

void Gra::WallCollision(Pilka& pilka, RenderTarget& target)
{
    if (pilka.left() < 0)
        pilka.predkosc.x = pilka.predkoscP;

    if (pilka.right() > target.getSize().x)
        pilka.predkosc.x = -pilka.predkoscP;

    if (pilka.top() < 0)
         pilka.predkosc.y = pilka.predkoscP;

    if (pilka.bottom() > target.getSize().y || punkty == 77)
    {
        Endgame = true;
    }
    else
    {
        Endgame = false;
    }
        
    
}

void Gra::update(RenderTarget& target)
{
    //paletka
    setLevel(level);
    paletka.setpaletkaSize(szerokosc_paletki);
    paletka.update(target);

    //pilka
    pilka.update();
    WallCollision(pilka, target);

    //klocki
    updateklocki();

    testCollision(paletka, pilka);
    //tekst
    updateText();
    //Ksiezyc
    updateKsiezyc(target);
    
}

void Gra::render(RenderTarget& target)
{
    for (auto* pucha : ksiezyc)
    {
        pucha->render(target);
    }

    paletka.render(target);
    pilka.render(target);
    rendertext(target);

    for (auto klocek : klocki)
    {
        klocek.render(target);
    }
    
}

void Gra::updateKsiezyc(RenderTarget& target)
{
    unsigned counter = 0;
    
    for (auto* pucha : ksiezyc)
    {
        pucha->update();

        if (pucha->getPosY() >= target.getSize().y)
        {
            delete ksiezyc.at(counter);

            ksiezyc.erase(ksiezyc.begin() + counter);
            --counter;

            ilosc_puchatkow++;
        }
        counter++;
    }

    if (timer == 1000)
    {
        ksiezyc.push_back(new Ksiezyc(rand() % szerokosc_okna, 0.f));

        timer = 0;
    }
    timer++;

}

void Gra::initFont()
{
    if (!font.loadFromFile("mohicon/Mohican.ttf"))
    {
        cout << "No font is here";
    }
}

void Gra::updateText()
{
    stringstream ss;

    ss << "points: " << punkty;

    text.setString(ss.str());

}

void Gra::initText()
{
    text.setFont(font);
    text.setCharacterSize(30);
    text.setPosition(25, 10);
    text.setFillColor(sf::Color(109, 62, 216));
    text.setString("none");
}

void Gra::rendertext(RenderTarget& target)
{
    target.draw(text);
}

void Gra::setLevel(int poziom)
{
    switch (poziom)
    {
    case(1):
        szerokosc_paletki = 150.f;
        break;
    case(2):
        szerokosc_paletki = 80.f;
        break;
    case(3):
        szerokosc_paletki = 40.f;
        break;
    }
}


template<class T1, class T2>
inline bool Gra::isIntersecting(T1& mA, T2& mB)
{
	return mA.right() >= mB.left() && mA.left() <= mB.right() &&

		mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

