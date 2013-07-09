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


void World::addEntity(Entity* e)
{
	entities.push_back(e);
}

void World::addConstraint(Constraint* c)
{
	constraints.push_back(c);

}

void World::printInfo()
{
	std::cout<<"Entities: "<<entities.size()<<", Constraints: "<<constraints.size()<<std::endl;

}