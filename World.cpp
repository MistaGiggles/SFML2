#include "stdafx.h"
#include "World.h"


World::World(void)
{
	gravity.x = gravity.y = 0;
}


World::~World(void)
{

}




void World::updateImpulses(float dt)
{

	// Apply impules produced by constraints
	for (auto it = constraints.begin(); it != constraints.end(); it++)
	{
		
		(*(*it)).apply(dt);
		
	}

	// Apply external impules to all entities
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		// Gravity
		if ( (**it).state.inversemass != 0)
			(**it).state.applyImpulse(gravity * dt * (**it).state.mass);


		// Air Resistances  F = C* v^2
		if ( (**it).state.inversemass != 0)
		{
			sf::Vector2<float> vel = (**it).state.v;
			float Cd = 0.47;
			sf::Vector2<float> p;
			p.x = -0.5f * vel.x * vel.x * Cd * dt;
			p.y = -0.5f * vel.y * vel.y * Cd * dt;
			(**it).state.applyImpulse(p);
		}
		

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

std::shared_ptr<Constraint> World::createSpring(std::shared_ptr<Entity> _a, std::shared_ptr<Entity>_b, float k, float d)
{
	std::shared_ptr<Spring> c = std::make_shared<Spring>(_a, _b, k , d);
	//(*c).setParams(k, d);
	addConstraint(c);
	return c;
}


void World::setGrav(float x, float y)
{
	gravity.x = x;
	gravity.y = y;
}