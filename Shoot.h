#pragma once
#include <SFML/Graphics.hpp>

class Shoot : public sf::Transformable, public sf::Drawable {
protected:
	float posx = 0;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2f _direction;
	sf::Clock _moveClock;
	float _speed = 1000;

public:
	Shoot();
	Shoot(sf::Sprite sprite) : _sprite(sprite) {}

	void Update();
	void setDirection(sf::Vector2f newDir);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};