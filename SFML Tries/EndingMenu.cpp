#include "EndingMenu.h"
#include "stdafx.h"

EndingMenu::MenuResults EndingMenu::Show(sf::RenderWindow& window)
{
	//Load Menu Image from file
	sf::Texture image;
	image.loadFromFile("images/ending_screen.png");
	sf::Sprite sprite(image);

	//Setup Clickable Regions based on screen coordinates

	//Play Game button item coordinates
	MenuItems playButton;
	playButton.rect.top = 340;
	playButton.rect.height = 490;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	//Exit Game button item coordinates
	MenuItems exitButton;
	exitButton.rect.top = 500;
	exitButton.rect.height = 650;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.action = Exit;
	_menuItems.push_back(playButton);
	_menuItems.push_back((exitButton));

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

EndingMenu::MenuResults EndingMenu::HandleClick(int x, int y)
{
	std::list<MenuItems>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.height > y&&
			menuItemRect.top < y &&
			menuItemRect.left < x &&
			menuItemRect.width > x)
		{
			return (*it).action;
		}
	}

	return Nothing;
}

EndingMenu::MenuResults EndingMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			if (menuEvent.type == sf::Event::Closed)
				return Exit;
		}
	}
}


