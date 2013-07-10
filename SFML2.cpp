// SFML2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <sstream>
#include "RK4.h"
#include "Entity.h"
#include "Spring.h"
#include "Gravity.h"
#include "World.h"



int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	sf::Clock clock;
	float time = 0;
	float dtime = 0;
	float accumulator = 0;
	float frameTime = 0.016f;

	bool joystick = false;
	bool fire = false;

	if (sf::Joystick::isConnected(0))
	{
		// joystick number 0 is connected
		std::cout<<"Found Joystick!"<<std::endl;
		joystick = true;
	}


	int joy = 0;
	int numAxis = 3;

	World world;
	world.setGrav(0, 100000);
	world.createSpring(world.createBasic(400,200, 0), world.createBasic(200,150, 1), 500, 10);


	/*
	1)		void updateImpulses(float dt);
	2)		void integrate(float time, float frametime);
	3)		void applyUpdates(float dt);
	4)		void render( sf::RenderTarget& display, float t, float dt);
	*/
	while (window.isOpen())
	{
		dtime = (float) clock.restart().asSeconds();
		time += dtime;

		if(dtime > 0.25f)
			dtime = 0.25f;

		accumulator += dtime;
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}	
			if (event.type == sf::Event::MouseButtonPressed) {


			}

			if(event.type == sf::Event::JoystickButtonPressed) {

			}

			if(event.type == sf::Event::JoystickMoved) {
				//std::cout<<"Axis: "<<event.joystickMove.axis<<" Moved"<<std::endl;
				//int axis = event.joystickMove.axis;
				//int pos = event.joystickMove.position;

			}
		}


		while(accumulator >= dtime)
		{
			world.updateImpulses(frameTime);
			world.integrate(time, frameTime);
			world.applyUpdates(frameTime);

			//RK4::integrate(b1.state, time, frameTime);
			//RK4::integrate(b2.state, time, frameTime);
			accumulator -= frameTime;

		}

		window.clear();

		world.render(window);
		//world.printInfo();

		window.display();

	}

	return 0;
}

