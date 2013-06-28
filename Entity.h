#pragma once
#include "RK4.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>


class Entity
{
public:
	Entity(void);
	~Entity(void);
	RK4::State state;
	sf::CircleShape shape;

	

	void update() {
		shape.setPosition(state.x);
	}

};

