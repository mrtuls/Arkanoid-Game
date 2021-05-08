#include"Top.h"


//------------------------------------------------------------------------------
// *** constructor(kurucu) fonksiyon ***

Top::Top(float x, float y, float s)
	: Top_ (10), hiz_(s), direction_(0.75f, 1.0f)
{	  Top_.setFillColor(sf::Color::Green);
	Top_.setPosition(x, y);
	normalize();
}


//------------------------------------------------------------------------------
// *** public fonksiyon ***

void Top::move (const sf::Time& deltaTime)
{
	Top_.move (direction_ * hiz_ * deltaTime.asSeconds());
}

void Top::change_direction(const sf::Vector2f& transform)
{
	direction_.x *= transform.x;
	direction_.y *= transform.y;
	normalize();
}

void Top::change_orientation(const sf::Vector2f& add)
{
	direction_.x += add.x;
	direction_.y += add.y;
	normalize();
}

void Top::ivme(float acc)
{
	hiz_ += acc;
}


//------------------------------------------------------------------------------
// *** private fonksiyon ***

void Top::normalize()
{
	float dx = direction_.x;
	float dy = direction_.y;
	float length = float(sqrt(dx*dx + dy*dy));
	direction_ = direction_ / length;
}
