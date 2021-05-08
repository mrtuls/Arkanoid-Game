#ifndef BLOKLAR_H
#define BLOKLAR_H


#include<SFML/Graphics.hpp>

class Bloklar  //sýnýf tanýmý
{
public:
	enum carpismaTuru //enum yapisi ile yatay dikey degiskenlerini tanimlama
	{
		Yatay, Dikey
	};

public:
	Bloklar (float x=0, float y=0, int l=1);

	carpismaTuru carpisma (const sf::FloatRect& carpisma);

	int life () const { return life_; }
	const sf::RectangleShape& bloklar () const { return Bloklar_; }

private:
	sf::RectangleShape Bloklar_;

	int life_;
};


#endif
