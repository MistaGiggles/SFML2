#include "stdafx.h"
#include "Spring.h"




Spring::~Spring(void)
{
}


void Spring::apply(float dt)
{
	RK4::springBetween(Constraint::a.state, Constraint::b.state, k, b);
	//Constraint::a.state.applyImpulse(RK4::springForce(Constraint::a.state, dt, dt);
}

void Spring::setParams(float _k, float _b) 
{
	k = _k/2.0f;
	b = _b/2.0f;
}