#include "MouseCtrls.hpp"
#include "Window.hpp"

MouseCtrls::MouseCtrls() {
	this->window = nullptr;
	for (int btn = 0; btn < MouseCtrls::btnCount; btn++) {
		this->state[btn] = IDLE;
	}
}

MouseCtrls::MouseCtrls(class Window* _window) {
	this->window = _window;
	for (int btn = 0; btn < MouseCtrls::btnCount; btn++) {
		this->state[btn] = IDLE;
	}
}

void MouseCtrls::update() {
	for (int btn = 0; btn < MouseCtrls::btnCount; btn++) {
		bool clicked = false;
		if (this->window->hasFocus()) {
			clicked = sf::Mouse::isButtonPressed((sf::Mouse::Button)btn);
		}

		if (clicked) {
			if (this->state[btn] == IDLE) this->state[btn] = CLICK;
			else this->state[btn] = HOLD;
		}
		else {
			if (this->state[btn] == HOLD) this->state[btn] = RELEASE;
			else this->state[btn] = IDLE;
		}
	}
}

bool MouseCtrls::idle(sf::Mouse::Button _btn) {
	return this->state[_btn] == RELEASE || this->state[_btn] == IDLE;
}

bool MouseCtrls::clicked(sf::Mouse::Button _btn) {
	return this->state[_btn] == CLICK;
}

bool MouseCtrls::held(sf::Mouse::Button _btn) {
	return this->state[_btn] == CLICK || this->state[_btn] == HOLD;
}

bool MouseCtrls::released(sf::Mouse::Button _btn) {
	return this->state[_btn] == RELEASE;
}