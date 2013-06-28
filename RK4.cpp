#include "stdafx.h"
#include "RK4.h"

using namespace sf;








 RK4::Derivative  RK4::evaluate( State& initial, float t, float dt,  Derivative &d)
{
	State state;
	state.x = initial.x + d.dx*dt;
	state.p = initial.p + d.dv*dt;

	Derivative output;
	output.dx = state.p * initial.inversemass;
	
	//output.dv = springForce(state, t, dt);
	output.dv = initial.impulses;
	//std::cout<<"Spring: "<<output.dv.x<<", "<<output.dv.y<<std::endl;

	return output;
}

sf::Vector2<float> RK4::springForce(State state, float t, float dt)
{
	const sf::Vector2<float> springPos(50,100);
	const sf::Vector2<float> springPos2(150,100);
	const float k = 10;
	const float b = 0.5f;
	return (-k * ( state.x - springPos ) - b*state.p) + sf::Vector2<float>(0, 500) + (-k * ( state.x - springPos2 ) - b*state.p)  ;
}

void RK4::springBetween(State& o1, State& o2, float k, float b)
{
	const sf::Vector2<float> d12 = o2.x - o1.x;
	const sf::Vector2<float> d21 = o1.x - o2.x;
	o1.applyImpulse((-k * d21 - b*o1.p));
	o2.applyImpulse(-k * d12 - b*o2.p);

	

}

void  RK4::integrate(State &state, float t, float dt)
{
	Derivative a = evaluate(state, t, 0.0f, Derivative());
	Derivative b = evaluate(state, t, dt*0.5f, a);
	Derivative c = evaluate(state, t, dt*0.5f, b);
	Derivative d = evaluate(state, t, dt, c);

	sf::Vector2<float> dxdt = 1.0f/6.0f * (a.dx + 2.0f*(b.dx + c.dx) + d.dx);
	sf::Vector2<float> dvdt = 1.0f/6.0f * (a.dv + 2.0f*(b.dv + c.dv) + d.dv);

	state.x = state.x + dxdt * dt;
	state.p = state.p + dvdt * dt;
	
	state.recalculate();
}