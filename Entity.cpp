#include "stdafx.h"
#include "Entity.h"


Entity::Entity(void)
{
	shape.setRadius(10.f);
	shape.setFillColor(sf::Color::Red);
}


Entity::~Entity(void)
{
}
