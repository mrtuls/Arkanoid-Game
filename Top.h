#ifndef Top_H
#define Top_H


#include<SFML/Graphics.hpp>

class Top //class tanimlari
{
public: //public ögelerin ve özelliklerininin tanimlanmasi
	Top(float x=0, float y=0, float s=200.0f);
	//topun hareketleri,yonunun tanimlanmasi
	void move(const sf::Time& deltaTime);
	void change_direction(const sf::Vector2f& transform = sf::Vector2f(1.0f, 1.0f)); 
	void change_orientation(const sf::Vector2f& add = sf::Vector2f(0.0f, 0.0f));
	void ivme(float acc = 0.0f);

	const sf::CircleShape& top() const //topun sekli
		{
			return Top_;
		}
	const sf::Vector2f& direction() const
		{
			return direction_;
		}

private:
	void normalize();

private:
	sf::CircleShape Top_;
	float hiz_;
	sf::Vector2f direction_;
};


#endif
