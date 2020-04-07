#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	//Get the image in the folder and set it as a texture to display it
	
	sf::Texture image;
	if (image.loadFromFile("images/SplashScreen.png") != true)
	{
		return;
	}
	sf::Sprite sprite(image);

	renderWindow.draw(sprite);
	renderWindow.display();

	//The different events that triggers the dismissal of the splashscreen.
	
	sf::Event event;
	while (true)
	{
		while (renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}