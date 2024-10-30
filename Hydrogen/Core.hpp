#pragma once
#include "toolbox/toolbox.hpp"
#include "Window.hpp"
#include "controls/Mouse.hpp"
#include "controls/Keyboard.hpp"

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
	enum GameState state;
	bool initPending;
	Window window;

	bool stateChangePending;
	enum GameState nextState;
	ctrl::Mouse mouse;
	ctrl::Keyboard kb;

	void initState();
public:
	Core();

	void init();
	void update();
	void render();
	void unload();

	GameState getState() { return this->state; }
	void requestStateChange(GameState _s);
	void changeState();

	bool windowIsOpen() { return this->window.isOpen(); }
	void beginRendering();
	void endRendering();
};

