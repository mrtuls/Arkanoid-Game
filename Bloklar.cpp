#include"Bloklar.h"





Bloklar::Bloklar (float x, float y, int l)  //bloklarýn konumu ve özellikleri
	: Bloklar_(sf::Vector2f(75, 20)),
	  life_(1)
{
	Bloklar_.setPosition(x, y);                     
	Bloklar_.setFillColor(sf::Color::Cyan);
}


//------------------------------------------------------------------------------
// *** Public Fonksiyon ***

Bloklar::carpismaTuru Bloklar::carpisma (const sf::FloatRect& carpisma)
{
	--life_;


	sf::Vector2f carpismaTop
		(carpisma.left + carpisma.width/2,
		 carpisma.top);

	sf::Vector2f blokPosition = Bloklar_.getPosition();
	float blokGenislik = Bloklar_.getSize().x;
	float blokYukseklik = Bloklar_.getSize().y;

	if (carpismaTop.x < blokPosition.x + 19* blokGenislik /20 &&
		carpismaTop.x > blokPosition.x + 1* blokGenislik /20 &&
		carpismaTop.y < blokPosition.y + blokYukseklik &&
		carpismaTop.y > blokPosition.y)
	{
		return Yatay;
	}
	else
	{
		return Dikey;
	}
}

