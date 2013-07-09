#pragma once
#include "RK4.h"
#include "Entity.h"
#include "Constraint.h"
#include "Spring.h"
#include "Gravity.h"
#include <vector>
class World
{
public:
	World(void);
	~World(void);
	std::vector<Entity*> entities;
	std::vector<Constraint*> constraints;

	void updateImpulses(float dt);
	void integrate(float time, float frametime);
	void applyUpdates(float dt);
	void render( sf::RenderTarget& display);
	
	void addEntity(Entity* e);
	void addConstraint(Constraint* c);

	void printInfo();

private:
	
	

};

