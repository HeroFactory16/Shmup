#pragma once
#include <SFML/Graphics.hpp>

class Explosion : public sf::Transformable, public sf::Drawable {
protected:
	int i = 0;
	sf::Clock _animClock;
	sf::Sprite _sprite;
	sf::Texture _texture;

public:
	Explosion();
	Explosion(sf::Vector2f);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void Update();

	void setSprite(sf::Sprite sprite);
};