#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

class EndingMenu
{
public:
	enum MenuResult { Nothing, Exit, Play };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};
	MenuResult Show(sf::RenderWindow& window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};

#pragma once
