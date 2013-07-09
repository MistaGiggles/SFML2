#include "stdafx.h"
#include "World.h"


World::World(void)
{

}


World::~World(void)
{

}




void World::updateImpulses(float dt)
{
	for (auto it = constraints.begin(); it != constraints.end(); it++)
	{
		(*(*it)).apply(dt);
		
	}
}



void World::integrate(float time, float frametime)
{
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		RK4::integrate( (*(*it)).state , time, frametime);
	}
}

void World::applyUpdates(float dt)
{
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		(*(*it)).update();
		
	}
}

void World::render( sf::RenderTarget& display)
{
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		(*(*it)).render(display);
	}

	for (auto it = constraints.begin(); it != constraints.end(); it++)
	{
		(*(*it)).render(display);
	}
}


void World::addEntity(std::shared_ptr<Entity> e)
{
	entities.push_back(e);
}

void World::addConstraint(std::shared_ptr<Constraint> c)
{
	constraints.push_back(c);

}

void World::printInfo()
{
	std::cout<<"Entities: "<<entities.size()<<", Constraints: "<<constraints.size()<<std::endl;

}

std::shared_ptr<Entity> World::createBasic(float x, float y, float m)
{
	std::shared_ptr<Entity> e = std::make_shared<Entity>(x,y,m);
	(*e).state.x.x = x;
	(*e).state.x.y = y;
	addEntity(e);
	return e;
}

std::shared_ptr<Constraint> World::createSpring(std::shared_ptr<Entity> _a, std::shared_ptr<Entity>_b)
{
	std::shared_ptr<Spring> c = std::make_shared<Spring>(_a, _b);
	(*c).setParams(10, 0.1f);
	addConstraint(c);
	return c;
}