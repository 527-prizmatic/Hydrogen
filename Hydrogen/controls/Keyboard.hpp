/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///						 == FILE NAME ==					 ///
///						   Keyboard.hpp						 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Basic, flexible keyboard control handler, simplifying	 ///
///  keybind management through the use of an easy-to-use	 ///
///  keybind registry system.								 ///
/// -------------------------------------------------------- ///

#pragma once
#include "../toolbox/toolbox.hpp"
#include <vector>

class Window;

namespace ctrl {
	/// Individual registry entry for the keybind registry
	class Keybind {
	private:
		std::string id; /// String ID for the keybind
		sf::Keyboard::Key key; /// Associated key
		ButtonState state; /// Current status of the associated key

	public:
		/// Constructs a new keybind based on its name and the associated key.
		Keybind(std::string _str, sf::Keyboard::Key _key);

		const std::string getId() { return this->id; }
		const sf::Keyboard::Key getKey() { return this->key; }
		const ButtonState getState() { return this->state; }

		/// Changes the bound key
		void setKey(const sf::Keyboard::Key _key) { this->key = _key; }
		/// Defines a key's current status.
		/// Technical only, do not use
		void setState(const ButtonState _state) { this->state = _state; }
	};

	/// Keybind registry and keyboard controls handler
	class Keyboard {
	private:
		int keyCtrlCount; /// Amount of registered keybinds

		class Window* window; /// Linked window, for checking window focus
		std::vector<Keybind> keyReg; /// Keybind registry
	public:
		Keyboard();
		Keyboard(Window* _window);
		void setWindow(Window* _window) { this->window = _window; }

		/// Registers a new keybind.
		/// This function is ignored if a keybind with the given name already exists.
		Keyboard& addKey(std::string _str, sf::Keyboard::Key _key);
		/// Rebinds the requested keybind to a new key.
		Keyboard& setKey(std::string _str, sf::Keyboard::Key _key);

		/// Monitors keyboard status and updates the keybind registry's contents accordingly.
		void update();

		/// \return Whether the requested keybind is idle (continuous)
		bool idle(std::string _str);
		/// \return Whether the requested keybind was just pressed (1-tick pulse)
		bool pressed(std::string _str);
		/// \return Whether the requested keybind is being held down (continuous)
		bool held(std::string _str);
		/// \return Whether the requested keybind was just released (1-tick pulse)
		bool released(std::string _str);
	};
}