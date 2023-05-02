#include "Engine.h"

Engine::Engine()
{

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_Window.create(VideoMode(resolution.x, resolution.y),"Particles",Style::Fullscreen);//fix
}


void Engine::run()
{
	Clock ClockTimer;
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen()) 
	{
		ClockTimer.restart();
		Time Seconds = ClockTimer.getElapsedTime();
		float TimeAsFloat;
		TimeAsFloat = Seconds.asSeconds();
		input();
		update(TimeAsFloat);
		draw();
	}

}
void Engine::input()
{
	
	int numPoints;
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{


			// Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				for (int i = 0; i < 5; i++)					//can change loops amount, and numPoint Range 
				{
					numPoints = rand()% (26) + 25;// rand header?
				}
			}

		}
	}

}
void Engine::update(float dtAsSeconds)
{
	for (int i = 0; i < m_particles.size(); i++)
	{
		if (m_particles.at(i).getTTL() > 0)
		{
			m_particles.at(i).update(m_particles.at(i).getTTL());

		}
		else
		{
			//delete m_particle.at(i)
		}
	}
}
void Engine::draw()
{

}
