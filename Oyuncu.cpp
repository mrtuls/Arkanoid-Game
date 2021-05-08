#include<iostream>

#include<SFML/Graphics.hpp>

#include"Oyuncu.h"


//------------------------------------------------------------------------------
// *** Static �zellikler ***

// Piksel/Saniye h�z�
const float Oyuncu::hiz_ = 400.0f;


//------------------------------------------------------------------------------
// *** constructor(kurucu)fonksiyon ***

Oyuncu::Oyuncu(float x, float y)
	: paddle_(sf::Vector2f(200.0f, 20.0f))
{	  paddle_.setFillColor(sf::Color::Blue);
	paddle_.setPosition(x, y);//paddle pozisyon konumlandirilmasi
}


//------------------------------------------------------------------------------
// *** public fonksiyon ***

void Oyuncu::move(const sf::Vector2f& direction, const sf::Time& deltaTime)
{
	paddle_.move(direction * hiz_ * deltaTime.asSeconds()); //paddle'�n zamana g�re h�z� ve hareketi
}
