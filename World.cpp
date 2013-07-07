#include "stdafx.h"
#include "World.h"


World::World(void)
{

}


World::~World(void)
{

}


void World::run()
{
	
	
}

void World::updateImpulses(float dt)
{
	for (auto it = constraints.begin(); it != constraints.end(); it++)
	{
		(*it).apply(dt);
	}
}



void World::integrate(float time, float frametime)
{
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		RK4::integrate( (*it).state , time, frametime);
	}
}

void World::applyUpdates(float dt)
{
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		(*it).update();
	}
}

void World::render()
{

}