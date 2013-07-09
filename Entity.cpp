#include "stdafx.h"
#include "Entity.h"


Entity::Entity(void)
{
	loadDefault();
}


Entity::~Entity(void)
{
}


void Entity::render(sf::RenderTarget& display)
{
	display.draw(sprite);
}

void Entity::update()
{
		sprite.setPosition(state.x);
}

void Entity::loadDefault()
{
	img.loadFromFile("Circle.png");
	
	sprite.setTexture(img);
	
	sprite.setOrigin(img.getSize().x / 2.0f, img.getSize().y / 2.0f);
}