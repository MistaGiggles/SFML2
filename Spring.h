#pragma once
#include "constraint.h"
#include <SFML/Graphics.hpp>
class Spring :
	public Constraint
{
public:
	using Constraint::apply;
	Spring(std::shared_ptr<Entity> _a, std::shared_ptr<Entity> _b) : Constraint(_a, _b) {};
	void apply(float dt);
	~Spring(void);
	void setParams(float _k, float _b);
	void render(sf::RenderTarget& display);
	//sf::Vertex[] getPoints();

	float k;
	float d;
};

