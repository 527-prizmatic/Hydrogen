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

namespace ctrl {
	class Mouse {
	private:
		class Window* window;

	public:
		Mouse();
		Mouse(class Window* _window);
		void setWindow(class Window* _window) { this->window = _window; }
		bool lClick();
		bool rClick();
	};
}