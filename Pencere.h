#ifndef PENCERE_H
#define PENCERE_H



#include<SFML/Graphics.hpp>

class Pencere //pencere sýnýfýnda pencere özelliklerinin tanýmlanmasý 
{
public:
	Pencere(unsigned int genislik, unsigned int yukseklik,
		   const sf::String& title,
		   sf::Uint32 style = sf::Style::Default);

	bool isOpen()
		{ return pencere_.isOpen(); }

	bool pollEvent(sf::Event& ev)
		{ return pencere_.pollEvent(ev); }

	void close()
		{ pencere_.close(); }

	void clear(const sf::Color& color = sf::Color(0,0,0,255))
		{ pencere_.clear(color); }

	void draw (const sf::Drawable& drawable)
		{ pencere_.draw(drawable); }

	void display()
		{ pencere_.display(); }

	bool carpismaSol(const sf::FloatRect& object) const;
	bool carpismaSag(const sf::FloatRect& object) const;
	bool carpismaUst(const sf::FloatRect& object) const;
	bool carpismaAlt(const sf::FloatRect& object) const;

private:
	sf::RenderWindow pencere_;
};



#endif
