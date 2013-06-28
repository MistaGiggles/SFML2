#pragma once
#include "constraint.h"
class Gravity :
	public Constraint
{
public:
	using Constraint::apply;
	Gravity(Entity& _a, Entity& _b) : Constraint(_a, _b) {};
	void setParam(float _g);
	void apply(float dt);
	~Gravity(void);

	float g;
};

