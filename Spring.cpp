#include "stdafx.h"
#include "Spring.h"




Spring::~Spring(void)
{
}


void Spring::apply(float dt)
{
	RK4::springBetween((*Constraint::a).state, (*Constraint::b).state, k, d);
	//Constraint::a.state.applyImpulse(RK4::springForce(Constraint::a.state, dt, dt);
	
}

void Spring::setParams(float _k, float _d) 
{
	k = _k/2.0f;
	d = _d/2.0f;
}

void Spring::render(sf::RenderTarget& display)
{
	sf::Vertex line[] = {sf::Vertex((*a).state.x), sf::Vertex((*b).state.x)};
	display.draw(line,2,sf::Lines);

}