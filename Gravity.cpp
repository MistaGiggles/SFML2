#include "stdafx.h"
#include "Gravity.h"




Gravity::~Gravity(void)
{
}


void Gravity::apply(float dt)
{
	Constraint::a.state.applyImpulse(0, g);
}

void Gravity::setParam(float _g)
{
	g = _g;
}