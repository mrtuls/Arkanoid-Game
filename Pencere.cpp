#include"SFML/Graphics.hpp"

#include"Pencere.h"


//------------------------------------------------------------------------------
// *** constructor kýsmý ***
Pencere::Pencere(unsigned int genislik, unsigned int yukseklik,
			   const sf::String& title,
			   sf::Uint32 style)
			   : pencere_(sf::VideoMode(genislik, yukseklik), title, style)
{
}


//------------------------------------------------------------------------------
// *** üye fonksiyonlar ***

bool Pencere::carpismaSol(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(-51, 0, 50, pencere_.getSize().y));
}

bool Pencere::carpismaSag(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(pencere_.getSize().x-1, 0, 50, pencere_.getSize().y));
}

bool Pencere::carpismaUst(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(0, -51, pencere_.getSize().x, 50));
}

bool Pencere::carpismaAlt(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(0, pencere_.getSize().y-1, pencere_.getSize().x, 50));
}
