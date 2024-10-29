#include "Core.hpp"
#include "BouncingBox.hpp"

GameState Core::state = GAME;
bool Core::initPending = true;
bool Core::firstInit = true;
Window Core::window;
bool Core::stateChangePending = false;
enum GameState Core::nextState = NONE;
ctrl::Mouse Core::mouseCtrl;

void Core::init() {
	if (firstInit) initFirst();
	if (initPending) initState();
}

void Core::initFirst() {
	firstInit = false;
	Core::window = Window(800U, 600U, "pavouk", false);
	Core::mouseCtrl.setWindow(&Core::window);
}

void Core::initState() {
	initPending = false;

	if (state == GameState::INTRO) {

	}
	else if (state == GameState::MENU) {

	}
	else if (state == GameState::GAME) {
		for (int i = 0; i < 100; i++) {
			BouncingBox::create(BouncingBox(sf::Vector2f(rand() % 600 + 50.f, rand() % 400 + 50.f), vect::normalize(sf::Vector2f(rand() % 201 - 100.f, rand() % 201 - 100.f)) * 100.f, sf::Vector2f(10.f, 10.f)));
		}
	}
}

void Core::update() {
	tutil::restart();
	window.update();

	if (state == GameState::INTRO) {

	}
	else if (state == GameState::MENU) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B) || mouseCtrl.lClick()) requestStateChange(GameState::GAME);
	}
	else if (state == GameState::GAME) {
		BouncingBox::updateAll(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) requestStateChange(GameState::MENU);
	}
	
}

void Core::render() {

	if (state == GameState::INTRO) {

	}
	else if (state == GameState::MENU) {

	}
	else if (state == GameState::GAME) {
		BouncingBox::renderAll(window);
	}
}

void Core::unload() {
	if (state == GameState::INTRO) {

	}
	else if (state == GameState::MENU) {

	}
	else if (state == GameState::GAME) {
		BouncingBox::clearList();
	}
}

void Core::requestStateChange(GameState _s) {
	if (_s == NONE) return;
	stateChangePending = true;
	nextState = _s;
}

void Core::changeState() {
	if (stateChangePending) {
		stateChangePending = false;
		if (nextState == NONE) return;
		Core::unload();
		state = nextState;
		initPending = true;
		Core::init();
		nextState = NONE;
	}
}

void Core::beginRendering() { Core::window.beginRendering(); }
void Core::endRendering() { Core::window.endRendering(); }