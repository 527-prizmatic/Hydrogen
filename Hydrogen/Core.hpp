/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  The core of the state machine is based off a registry	 ///
///  system allowing to "register" game states to make		 ///
///  switching between states quick and easy. Also comes	 ///
///  with basic garbage collection utilities, although most	 ///
///  of that still needs to be implemented manually when	 ///
///  designing an individual game state.					 ///
/// -------------------------------------------------------- ///

#pragma once
#include <unordered_map>
#include "toolbox/toolbox.hpp"
#include "Window.hpp"
#include "controls/Mouse.hpp"
#include "controls/Keyboard.hpp"
#include "states/State.hpp"


typedef enum GameState GameState;
enum GameState {
	NONE,
	ALL,
	INTRO,
	MENU,
	GAME,
	END
};

class Core {
private:
	std::unordered_map<enum GameState, states::State*> stateReg; /// Registry of game states
	enum GameState state; /// Currently active game state
	bool initPending; /// Whether resource initialization should be performed at the beginning of the next tick
	Window window; /// Linked window object

	bool stateChangePending; /// Whether a state change has been requested
	enum GameState nextState; /// Which state the system will transition to at the end of the current tick
	ctrl::Mouse mouse; /// Linked mouse controls handler
	ctrl::Keyboard kb; /// Linked keyboard controls handler

	/// Initializes resources for the currently active game state.
	/// Does not check whether resources have already been initialized, so use with caution.
	/// If all is well there shouldn't be any need to manipulate this function.
	void initState();
public:
	/// Default state machine constructor; all internal resources, including window, controller handlers, etc. will be created,
	/// as well as a round of preinitialization be carried out for this state machine
	Core();
	
	/// Initializes resources for the currently active game state.
	void init();
	/// Computes tick updates for the currently active game state.
	void update();
	/// Renders objects on-screen for the currently active game state.
	void render();
	/// Destroys all resources allocated for and by the currently active game state, and clear all resource buffers.
	void unload();

	/// Registers a new game state into the state machine. Preinit only.
	Core& registerState(GameState _id, states::State* _state);
	/// \return The currently active game state
	GameState getState() { return this->state; }
	/// Queues a state machine change for the end of the current tick.
	/// This process is deferred to the end of a game loop to avoid interrupting a game loop halfway through (couldn't recall all the times a project crashed because of that).
	/// Only one state change may be requested at a time. Requesting another will override the previously-requested state change.
	void requestStateChange(GameState _s);
	/// Destroys all resources allocated for the currently active game state, then activates the queued one and initializes it.
	void changeState();

	bool windowIsOpen() { return this->window.isOpen(); }
	Window& getWindow() { return this->window; }
	ctrl::Mouse& getMouse() { return this->mouse; }
	ctrl::Keyboard& getKeyboard() { return this->kb; }
	/// Clears the associated game window to prepare for the next round of rendering.
	void beginRendering();
	/// Wraps up rendering and displays the associated game window on-screen.
	void endRendering();
};

