
#include<SFML/Graphics.hpp>

#include"Oyun.h"


//------------------------------------------------------------------------------
// *** constructor kýsmý ***

Oyun::Oyun()
	: pencere_(800, 600, "Arkanoid Oyunu",
			  sf::Style::Titlebar | sf::Style::Close),
	  oyuncu_(350, 550),
	  top_(400, 300, 300.0f)
{
	for (int i=sf::Keyboard::A; i!=sf::Keyboard::KeyCount; ++i)
	{
		sf::Keyboard::Key k = static_cast<sf::Keyboard::Key>(i);
		isButtonPressed_[k] = false;
	}

	generate_bloklar();
}


//------------------------------------------------------------------------------
// *** public fonksiyon: ***

void Oyun::run()
{
	sf::Clock clock;
	sf::Time soncarpismaZaman = sf::Time::Zero;
	while (pencere_.isOpen())
	{
		soncarpismaZaman = clock.restart();
		process_events();
		update(soncarpismaZaman);
		render();
	}
}


//*------------------------------------------------------------------------------
// *** private fonksiyonlar ***

void Oyun::process_events()
{
	sf::Event event;
	while (pencere_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			pencere_.close();
			break;
		case sf::Event::KeyPressed:
			isButtonPressed_.at(event.key.code) = true;
			break;
		case sf::Event::KeyReleased:
			isButtonPressed_.at(event.key.code) = false;
			break;
		default:
			// hiçbirþey yapmaz
			break;
		}
	}
}

void Oyun::update(const sf::Time& deltaTime) //oyun ayarlarý ve paddle hareketini saðlayan tuþ kombinasyonlarý
{
	sf::Vector2f oyuncuYon (0.0f, 0.0f);
	if (isButtonPressed_.at(sf::Keyboard::Right) |
		isButtonPressed_.at(sf::Keyboard::D))
	{
		oyuncuYon.x += 1.0f;
	}
	if (isButtonPressed_.at(sf::Keyboard::Left) |
		isButtonPressed_.at(sf::Keyboard::Q))
	{
		oyuncuYon.x -= 1.0f;
	}

	sf::FloatRect oyuncuSinirlari = oyuncu_.paddle().getGlobalBounds();

	// paddle'ýn pencere ile sýnýrýný kontrol etme
	if (pencere_.carpismaSol(oyuncuSinirlari) &&
		oyuncuYon.x < 0)
	{
		oyuncuYon = sf::Vector2f (0.0f, 0.0f);
	}
	if (pencere_.carpismaSag(oyuncuSinirlari) &&
		oyuncuYon.x > 0)
	{
		oyuncuYon = sf::Vector2f (0.0f, 0.0f);
	}


	sf::FloatRect topSinirlari = top_.top().getGlobalBounds();
	sf::Vector2f topDonusum (1.0f, 1.0f);
	sf::Vector2f topYonu = top_.direction();
	// topun pencere ile sinirlari
	if (pencere_.carpismaSol(topSinirlari) &&
		topYonu.x < 0)
	{
		topDonusum.x = -1.0f;
	}
	else if (pencere_.carpismaSag(topSinirlari) &&
		topYonu.x > 0)
	{
		topDonusum.x = -1.0f;
	}
	if (pencere_.carpismaUst(topSinirlari))
	{
		topDonusum.y = -1.0f;
	}

	// paddle ile topun carpismasini test etme ve topun yörüngesini buna göre deðiþtirme
	
	sf::Vector2f topArtis (0.0f, 0.0f);
	sf::FloatRect kesisim;
	float topIvmesi = 0.0f;
	if (oyuncuSinirlari.intersects(topSinirlari,kesisim) &&
		topYonu.y > 0)
	{
		float oyuncuUzunlugu = oyuncuSinirlari.width;
		float oyuncuOrta = oyuncuSinirlari.left + oyuncuUzunlugu/2;
		float Xnoktasindacarpisma = kesisim.left;

		topArtis.x = (2/oyuncuUzunlugu)*(Xnoktasindacarpisma-oyuncuOrta);
		topDonusum.y = -1.0f;
		topIvmesi = 5.0f;
	}

	// topun tuðla ile çarpýþmasýný tespit etme
	for (auto it = vBloklar_.begin(); it != vBloklar_.end(); ++it)
	{
		sf::FloatRect blokSinirlari ((*it).bloklar().getGlobalBounds());
		if (blokSinirlari.intersects(topSinirlari, kesisim))
		{
			Bloklar::carpismaTuru carpismaCesit  = (*it).carpisma(kesisim);
			if (carpismaCesit == Bloklar::Yatay)
			{
				topDonusum.y = -1.0f;
			}
			else
			{
				topDonusum.x = -1.0f;
			}
			
			if ((*it).life() <= 0)
			{
				vBloklar_.erase(it);
			}
			break;
		}
	}

	top_.change_direction(topDonusum);
	top_.change_orientation(topArtis);
	top_.ivme(topIvmesi);

	oyuncu_.move(oyuncuYon, deltaTime);
	top_.move(deltaTime);


	// oyunda baþarýlý ya da baþarýsýz olunca pencerenin kapanmasý
	if (pencere_.carpismaAlt(topSinirlari) ||
		vBloklar_.empty())
	{
		pencere_.close();
	}	   
}
 
void Oyun::render()
{
	pencere_.clear();

	pencere_.draw(oyuncu_.paddle());
	pencere_.draw(top_.top());
	for(size_t i=0; i<vBloklar_.size(); ++i)
	{
		pencere_.draw(vBloklar_.at(i).bloklar());
	}

	pencere_.display();
}

void Oyun::generate_bloklar()
{
	for (int y=0; y<5; ++y)
	{
		for (int x=0; x<10; ++x)
		{
			vBloklar_.push_back(Bloklar(x*77+10, y*22+10));
		}
	}
}
							 

