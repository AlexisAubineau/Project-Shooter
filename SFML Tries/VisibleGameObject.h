#pragma once
#include <string>
#include <SFML/Graphics.hpp>


namespace sf {
	class RenderWindow;
}

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);
	virtual void Update(float elaspedTime);

	virtual float GetWidth() const;
	virtual float GetHeight() const;

	virtual sf::Rect<float> GetBoundingRect() const;

	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded();

	sf::Sprite& GetSprite();

protected:
	

private:
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;
};
