#ifndef Oyun_H
#define Oyun_H

//heather dosyalar�n�n ve gerekli k�t�phanelerin �a�r�lmas�
#include<vector>
#include<map>
#include<SFML/Graphics.hpp>
#include"Pencere.h"
#include"Oyuncu.h"
#include"Top.h"
#include"Bloklar.h"

class Oyun
{
public:
	Oyun();

	void run();

private:
	void process_events();
	void update(const sf::Time& deltaTime);
	void render();
	
	void generate_bloklar();

private:
	Pencere pencere_;

	Oyuncu oyuncu_;
	Top top_;
	std::vector<Bloklar> vBloklar_;

	std::map<sf::Keyboard::Key, bool> isButtonPressed_;
};


#endif
