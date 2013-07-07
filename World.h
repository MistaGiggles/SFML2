#pragma once
#include "RK4.h"
#include "Entity.h"
#include "Constraint.h"
#include <vector>
class World
{
public:
	World(void);
	~World(void);
	std::vector<Entity> entities;
	std::vector<Constraint> constraints;

	void updateImpulses(float dt);
	void applyUpdates(float dt);
	void integrate(float time, float frametime);
	void run();
	void render();
	

private:
	float t;
};

