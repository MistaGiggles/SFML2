#include "stdafx.h"
#include "Entity.h"


Entity::Entity(void)
{
	img.loadFromFile("Circle.png");
	
	sprite.setTexture(img);
	
	sprite.setOrigin(img.getSize().x / 2.0f, img.getSize().y / 2.0f);
}


Entity::~Entity(void)
{
}
