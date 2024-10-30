#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

extern class Window;

namespace tutil {
	void restart();
	float getDelta();
}

namespace vect {
	float magnitude(sf::Vector2f _v);
	float magnitude2(sf::Vector2f _v);

	sf::Vector2f normalize(sf::Vector2f _v);
}