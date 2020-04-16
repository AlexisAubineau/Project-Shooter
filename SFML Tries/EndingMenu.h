#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

class EndingMenu
{
public:
	enum MenuResults { Nothing, Exit, Play };

	struct MenuItems
	{
	public:
		sf::Rect<int> rect;
		MenuResults action;
	};
	MenuResults Show(sf::RenderWindow& window);

private:
	MenuResults GetMenuResponse(sf::RenderWindow& window);
	MenuResults HandleClick(int x, int y);
	std::list<MenuItems> _menuItems;
};
