#include "stdafx.h"
#include "Game.h"
#include "EndingMenu.h"

sf::Sprite background;
sf::Texture background_texture;
void Game::Start(void)
{
//Checks the current state of the game before starting the game
	if (_gameState != Uninitialized)
		return;
//Creates the render window to display all our stuffs.
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "O Space by Patrick and Alexis");
	_mainWindow.setFramerateLimit(60);

	PlayerShip *player1 = new PlayerShip();
	player1->SetPosition(200, (SCREEN_WIDTH / 2));

	EnemyWaveSpawner* Enemies = new EnemyWaveSpawner();
	Enemies->SetPosition((SCREEN_WIDTH/2), (SCREEN_WIDTH / 2));

	
	background_texture.loadFromFile("images/background.png");
	background.setTexture(background_texture);

	_gameObjectManager.Add("Player1", player1);
	_gameObjectManager.Add("Enemy_Spawner", Enemies);
	_gameState = Game::ShowingSplash;

//As long as a state of the game Exists, the game will obviously stay open and continue its process. Unless ofc you close it.	
	while (!IsExisting())
	{
		GameLoop();
	}
	_mainWindow.close();
}

//

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}

void Game::ShowDeathMenu()
{
	EndingMenu endingMenu;
	EndingMenu::MenuResults result = endingMenu.Show(_mainWindow);
	switch (result)
	{
	case EndingMenu::Exit:
		_gameState = Game::ShowingMenu;
		break;
	case EndingMenu::Play:
		_gameState = Game::Playing;
		PlayerShip* player1 = new PlayerShip();
		player1->SetPosition(200, (SCREEN_WIDTH / 2));
		_gameObjectManager.Add("Player1", player1);
		break;
	}
}


bool Game::IsExisting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}


//The GameLoop

void Game::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
		switch (_gameState)
		{
			case Game::ShowingMenu:
				{
				ShowMenu();
				break;
				}
			case Game::ShowingSplash:
				{
				ShowSplashScreen();
				break;
				}
			case Game::Playing:
				{
				
				_mainWindow.clear((sf::Color(0, 0, 0)));
				_mainWindow.draw(background);
				_gameObjectManager.UpdateAll();
				_gameObjectManager.DrawAll(_mainWindow);
				
				_mainWindow.display();
					if(currentEvent.type == sf::Event::Closed)
					{
						_gameState = Game::Exiting;
					}
					if (_gameObjectManager.Get("Player1") == nullptr)
					{
						_gameState = Game::Death;
					}
					break;
				}
			case Game::Death:
				{
				ShowDeathMenu();
				break;
				}
	}
}

//Initialization of the gamestate incase something fails.

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;