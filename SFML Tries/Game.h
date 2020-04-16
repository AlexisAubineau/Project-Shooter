#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include  "PlayerShip.h"
#include "Enemy_Wave_Spawner.h"
#include "GameObjectManager.h"

class Game
{
public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	const static sf::InputStream& GetInput;
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;
	static GameObjectManager _gameObjectManager;

private:
	static bool IsExisting();
	static void GameLoop();

	static void ShowDeathMenu();
	static void ShowSplashScreen();
	static void ShowMenu();

	static sf::RenderWindow _mainWindow;

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting, Death };
	static GameState _gameState;
};
