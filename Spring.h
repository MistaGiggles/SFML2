#pragma once
#include "constraint.h"
#include <SFML/Graphics.hpp>
class Spring :
	public Constraint
{
public:
	using Constraint::apply;
	Spring(Entity& _a, Entity& _b) : Constraint(_a, _b) {};
	void apply(float dt);
	~Spring(void);
	void setParams(float _k, float _b);

	//sf::Vertex[] getPoints();

	float k;
	float b;
};

