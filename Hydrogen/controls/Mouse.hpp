#pragma once
#include "../toolbox/toolbox.hpp"

class Window;

namespace ctrl {
	/// Mouse controls handler
	class Mouse {
	private:
		static const int btnCount = sf::Mouse::Button::ButtonCount; /// Amount of available mouse buttons

		class Window* window; /// Linked window, for checking window focus
		ButtonState state[btnCount]; /// Status of each mouse button

	public:
		Mouse();
		Mouse(Window* _window);
		void setWindow(Window* _window) { this->window = _window; }

		/// Monitors mouse status and updates the statuses list accordingly.
		void update();

		/// \return Whether the requested button is idle (continuous)
		bool idle(sf::Mouse::Button _btn);
		/// \return Whether the requested button was just pressed (1-tick pulse)
		bool clicked(sf::Mouse::Button _btn);
		/// \return Whether the requested button is being held down (continuous)
		bool held(sf::Mouse::Button _btn);
		/// \return Whether the requested button was just released (1-tick pulse)
		bool released(sf::Mouse::Button _btn);
	};
}