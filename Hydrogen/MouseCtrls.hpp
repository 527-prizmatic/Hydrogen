#pragma once
#include "toolbox_proto.hpp"

extern class Window;

class MouseCtrls {
private:
	static const int btnCount = sf::Mouse::Button::ButtonCount;

	class Window* window;
	enum { IDLE, CLICK, HOLD, RELEASE } state[btnCount];

public:
	MouseCtrls();
	MouseCtrls(class Window* _window);
	void setWindow(class Window* _window) { this->window = _window; }

	void update();

	bool idle(sf::Mouse::Button _btn);
	bool clicked(sf::Mouse::Button _btn);
	bool held(sf::Mouse::Button _btn);
	bool released(sf::Mouse::Button _btn);
};