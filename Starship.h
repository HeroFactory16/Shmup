#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shoot.h"
#include "Explosion.h"

class Starship : public sf::Transformable, public sf::Drawable {
protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _direction;
	sf::Vector2f _lastDir = sf::Vector2f(0, -1);
	sf::Clock _moveClock;
	sf::Clock _shootClock;
	float _speed = 200.f;
	int _lifepoints = 3;
	std::vector<Shoot*> _amosFired;
	Explosion* _deathAnim;

public:
	Starship();
	Starship(sf::View mainView);
	Starship(float newSpeed);
	Starship(sf::Sprite sprite);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setSprite(sf::Sprite sprite);
	void shoot();
	void move();
	bool isDead();
	void OnDeath();
	Explosion* getExplosion();
	std::vector<Shoot*> getAmosFired();

	void Update();
};