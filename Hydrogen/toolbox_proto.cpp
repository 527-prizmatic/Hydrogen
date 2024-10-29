#include "toolbox_proto.hpp"
#include "Window.hpp"

namespace tutil {
	sf::Clock clock;
	float delta;

	void restart() {
		delta = clock.restart().asSeconds();
		if (delta > .1f) delta = 0.f;
	}

	float getDelta() {
		return delta;
	}
}

namespace vect {
	float magnitude(sf::Vector2f _v) {
		return sqrtf(magnitude2(_v));
	}

	float magnitude2(sf::Vector2f _v) {
		return _v.x * _v.x + _v.y * _v.y;
	}

	sf::Vector2f normalize(sf::Vector2f _v) {
		return _v / magnitude(_v);
	}

	sf::Vector2f polToRec(sf::Vector2f _v) {
		return sf::Vector2f();
	}
}

namespace ctrl {
	Mouse::Mouse() {
		this->window = nullptr;
	}

	Mouse::Mouse(class Window* _window) {
		this->window = _window;
	}

	bool Mouse::lClick() {
		if (this->window) return this->window->hasFocus() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
		else return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	bool Mouse::rClick() {
		if (this->window) return this->window->hasFocus() && sf::Mouse::isButtonPressed(sf::Mouse::Right);
		else return sf::Mouse::isButtonPressed(sf::Mouse::Right);
	}
}