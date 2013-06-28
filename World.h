#pragma once
#include "RK4.h"
#include "Entity.h"
#include <vector>
class World
{
public:
	World(void);
	~World(void);
	std::vector<Entity> entities;

	void updateImpulses(float dt);
	void applyUpdates(float dt);

private:
	float t;
};

