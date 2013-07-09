#pragma once
#include <memory>
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
	std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<Constraint>> constraints;

	void updateImpulses(float dt);
	void integrate(float time, float frametime);
	void applyUpdates(float dt);
	void render( sf::RenderTarget& display);
	
	void addEntity(std::shared_ptr<Entity> e);
	void addConstraint(std::shared_ptr<Constraint> c);

	void printInfo();


	std::shared_ptr<Entity> createBasic(float x, float y, float m);
	std::shared_ptr<Constraint> createSpring(std::shared_ptr<Entity> _a, std::shared_ptr<Entity>_b);

private:
	
	

};

