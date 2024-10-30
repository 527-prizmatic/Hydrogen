#include "Core.hpp"
#include "BouncingBox.hpp"

const std::string KeyOpenMenu = "OpenMenu";
const std::string KeyOpenGame = "OpenGame";

Core::Core() {
	this->window = Window(800U, 600U, "pavouk", false);
	this->mouse.setWindow(&this->window);
	this->kb.setWindow(&this->window);
	this->state = GAME;
	this->nextState = NONE;
	this->initPending = true;
	this->stateChangePending = false;

	this->kb.addKey(KeyOpenMenu, sf::Keyboard::Key::B);
	this->kb.addKey(KeyOpenGame, sf::Keyboard::Key::A);
}

void Core::init() {
	if (initPending) initState();
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
	this->window.update();
	this->mouse.update();
	this->kb.update();

	if (state == GameState::INTRO) {

	}
	else if (state == GameState::MENU) {
		if (this->kb.pressed(KeyOpenGame) || mouse.clicked(sf::Mouse::Left)) requestStateChange(GameState::GAME);
	}
	else if (state == GameState::GAME) {
		BouncingBox::updateAll(window);
		if (this->kb.pressed(KeyOpenMenu) || mouse.clicked(sf::Mouse::Left)) requestStateChange(GameState::MENU);
		if (this->mouse.clicked(sf::Mouse::Right)) this->kb.setKey(KeyOpenMenu, sf::Keyboard::Key::R);
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