#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Starship.h"

class Enemy : public Starship {
public:
	Enemy();

	void move();
	void shoot();
};