#pragma once

#include "RK4.h"
#include "Entity.h"

#include <SFML/Graphics.hpp>
class Constraint
{
public:
	Constraint(Entity& _a, Entity& _b): b(_b), a(_a) {};
	~Constraint(void);

	Entity& a;
	Entity& b;

	

	virtual void apply(float dt) {};
	virtual void render(sf::RenderTarget& display) {};
};

