#include "stdafx.h"
#include "Spring.h"




Spring::~Spring(void)
{
}


void Spring::apply(float dt)
{
	RK4::springBetween((*Constraint::a).state, (*Constraint::b).state, k, d, dt);
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
	sf::Vector2<float> posa = (*a).state.x;
	sf::Vector2<float> posb = (*b).state.x;

	sf::Vector2<float> res = posa - posb;
	float dist = res.x * res.x + res.y * res.y;
	float maxDist = maxLength * maxLength;

	float r = dist/maxDist;
	float b = 255;
	float g = 255;
	if(r > 1) { r = 1; b=g=0;}

	line[0].color = line[1].color = sf::Color(r*255, g, b);
	display.draw(line,2,sf::Lines);

}