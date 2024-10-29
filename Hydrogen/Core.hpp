#pragma once
#include "toolbox_proto.hpp"
#include "Window.hpp"

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
	static enum GameState state;
	static bool initPending;
	static bool firstInit;
	static Window window;

	static bool stateChangePending;
	static enum GameState nextState;

	static void initFirst();
	static void initState();

public:
	static void init();
	static void update();
	static void render();
	static void unload();

	static GameState getState() { return Core::state; }
	static void requestStateChange(GameState _s);
	static void changeState();

	static bool windowIsOpen() { return window.isOpen(); }
	static void beginRendering();
	static void endRendering();
};

