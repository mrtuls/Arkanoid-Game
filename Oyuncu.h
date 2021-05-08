#ifndef Oyuncu_H
#define Oyuncu_H



#include<SFML/Graphics.hpp>


class Oyuncu
{
public:
	Oyuncu(float x=0, float y=0);

	void move(const sf::Vector2f& direction, const sf::Time& deltaTime);

	const sf::RectangleShape& paddle() const
		{
			return paddle_;
		}

private://paddle sekli ve hiz tanimlanmasi
	sf::RectangleShape paddle_;

	static const float hiz_;
};



#endif
