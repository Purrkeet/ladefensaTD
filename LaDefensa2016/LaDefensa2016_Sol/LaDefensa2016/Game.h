#include <SFML/Graphics.hpp>
class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();
private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
};

Game::Game()
: mWindow(sf::VideoMode(640, 480), "Defensa de los Ancestros")
, mPlayer()
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
}
void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		/*case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;*/
		case sf::Event::Closed:
			mWindow.close();
			break;

		}
		
	}
}

void Game::update()
{

}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}