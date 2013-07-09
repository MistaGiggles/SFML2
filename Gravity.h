#pragma once
#include "constraint.h"
class Gravity :
	public Constraint
{
public:
	using Constraint::apply;
	Gravity(std::shared_ptr<Entity> _a, std::shared_ptr<Entity> _b) : Constraint(_a, _b) {};
	void setParam(float _g);
	void apply(float dt);
	~Gravity(void);

	float g;
};

