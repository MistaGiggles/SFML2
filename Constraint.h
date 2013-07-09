#pragma once
#include <memory>
#include "RK4.h"
#include "Entity.h"

#include <SFML/Graphics.hpp>
class Constraint
{
public:
	Constraint(std::shared_ptr<Entity> _a,std::shared_ptr<Entity> _b): b(_b), a(_a) {};
	~Constraint(void);

	std::shared_ptr<Entity> a;
	std::shared_ptr<Entity> b;

	

	virtual void apply(float dt) {};
	virtual void render(sf::RenderTarget& display) {};
};

