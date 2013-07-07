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



int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Red);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	
	Entity b1;
	Entity b2;
	Entity centre;

	centre.state.x.x = centre.state.x.y = 100;
	centre.state.inversemass = 0;
	
	b1.state.x.x = 20; b1.state.x.y = 20;
	b1.state.inversemass = 0.1f;
	
	b2.state.x.x = 180; b2.state.x.y = 60;


	Gravity g(b1, b2);
	g.setParam(100);
	Spring spr(b1, b2);

	Spring hold(centre, b1);
	hold.setParams(10, 0);
	spr.setParams(10,0);

	sf::Clock clock;
	float time = 0;
	float dtime = 0;
	float accumulator = 0;
	float frameTime = 0.01f;
	
	bool joystick = false;
	bool fire = false;

	if (sf::Joystick::isConnected(0))
	{
		// joystick number 0 is connected
		std::cout<<"Found Joystick!"<<std::endl;
		joystick = true;
	}

	sf::Font font;
	if(!font.loadFromFile("mode7.ttf"))
	{
		std::cout<<"Error loading font"<<std::endl;
	}
	int joy = 0;
	int numAxis = 3;
	


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
				
				//sf::Vector2<float> resultant = (sf::Vector2<float>) sf::Mouse::getPosition(window) - state.x;
				//state.applyImpulse(resultant.x * 10000, resultant.y * 10000);
				
				b1.state.print();

			}

			if(event.type == sf::Event::JoystickButtonPressed) {
				std::cout<<"Joystick: "<<event.joystickButton.button<<std::endl;
			}

			if(event.type == sf::Event::JoystickMoved) {
				//std::cout<<"Axis: "<<event.joystickMove.axis<<" Moved"<<std::endl;
				int axis = event.joystickMove.axis;
				int pos = event.joystickMove.position;


			}
			
				
			
        }

		
		while(accumulator >= dtime)
		{
			hold.apply(frameTime);
			spr.apply(frameTime);
			//g.apply(dtime);
		

			RK4::integrate(b1.state, time, frameTime);
			RK4::integrate(b2.state, time, frameTime);
			accumulator -= frameTime;
			
		}
		
		///std::stringstream sstm;
		///sstm << "FPS" << fps << std::endl;
		///window.setTitle(sstm.str());

		//RK4::integrate(centre.state, time, dtime);
		/*if (sf::Joystick::isButtonPressed(0, 0))
		{
			// yes: shoot!
			if(!fire)
				state.applyImpulse(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
			fire = true;
		} else {
			fire = false;
		}*/
		
		b1.update();
		b2.update();
		centre.update();
		

		window.clear();
		
        window.draw(b1.sprite);
		window.draw(b2.sprite);
		window.draw(centre.sprite);
		
		

		/*if(joystick) 
		{
			float jx = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float jy = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			sf::Vertex joy[] = {sf::Vertex(state.x), sf::Vertex(state.x + sf::Vector2f(jx,jy))};
			window.draw(joy,2,sf::Lines);
		}*/

        window.display();
	
    }

    return 0;
}

