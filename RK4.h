#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <iostream>

namespace RK4 {
struct State
	{
		sf::Vector2<float> x; // Position
		sf::Vector2<float> v; // Velocity
		sf::Vector2<float> p; // Momentum
		sf::Vector2<float> impulses;

		//void force(State& state, float t, float dt);

		//typedef sf::Vector2<float> (*forceFunction)(State&, float, float);

		//std::vector<forceFunction> constantForces;

		float mass;
		float inversemass;

		State() {
			mass = 1;
			v.x = v.y = 0;
			x.x = x.y = 0;
			inversemass = 1;
			impulses.x = impulses.y = 0;
		}

		State(float _x, float _y, float _im) {
			mass = 1.f/ _im;
			inversemass = _im;
			x.x = _x;
			x.y = _y;
			v.x = v.y = 0;
			impulses.x = impulses.y = 0;
		};

		State(float _x, float _y, float _vx, float _vy, float _im) {
			mass = 1.f / _im;
			inversemass =  _im;
			x.x = _x;
			x.y = _y;
			v.x = _vx;
			v.y = _vy;
			impulses.x = impulses.y = 0;

		};

		void prepMass() {
			mass = 1.0f / inversemass;
		}

		void setStatic() {
			inversemass = 0;
		}

		void recalculate() {
				// velocity = momentum * inverseMass
			v = p * inversemass;
			impulses.x = impulses.y = 0;

		}

		void applyImpulse(float _x, float _y) {
			impulses.x += _x;
			impulses.y += _y;
		}

		void applyImpulse(sf::Vector2<float> i) {
			impulses += i;
		}

		void print() {
			std::cout<<"Position: "<<x.x<<", "<<x.y<<std::endl;
			std::cout<<"Velocity: "<<v.x<<", "<<v.y<<std::endl;
			std::cout<<"Momentum: "<<p.x<<", "<<p.y<<std::endl;
			std::cout<<"Impulses: "<<impulses.x<<", "<<impulses.y<<std::endl;

		}

		


	};

	struct Derivative
	{
		sf::Vector2<float> dx; // derivative of position: momentum
		sf::Vector2<float> dv; // derivative of momentum: force
	};

	Derivative evaluate(State& initial, float t, float dt,  Derivative &d);

	sf::Vector2<float> springForce( State state, float t, float dt);
	void springBetween(State& o1, State& o2, float k, float b, float dt);

	void integrate(State &state, float t, float dt);
};