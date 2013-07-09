#pragma once
#include "RK4.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>


class Entity
{
public:
	Entity(void);
	Entity(float x, float y, float im) : state(x,y,im) {loadDefault();};
	~Entity(void);
	RK4::State state;
	sf::Sprite sprite;
	sf::Texture img;
	void loadDefault();

	

	void update() ;

	void render(sf::RenderTarget& display);

};

