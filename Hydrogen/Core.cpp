#include "Core.hpp"
#include "BouncingBox.hpp"
#include "Preinit.hpp"

Core::Core() {
	this->window = Window(800U, 600U, "pavouk", false);
	this->mouse.setWindow(&this->window);
	this->kb.setWindow(&this->window);
	this->state = GAME;
	this->nextState = NONE;
	this->initPending = true;
	this->stateChangePending = false;
	this->window.setView(new View(sf::Vector2f(0.f, 0.f), sf::Vector2f(256.f, 224.f)));

	preinit(*this);
	registerControls(*this);
}

void Core::init() {
	if (initPending) initState();
}

void Core::initState() {
	initPending = false;
	this->stateReg[this->state]->init();
}

void Core::update() {
	tutil::restart();
	this->mouse.update();
	this->kb.update();

	if (this->window.hasView()) {
		this->window.getView()->setSize(this->window.forceAspectRatio(sf::Vector2f(256.f, 224.f), 1.f));
		this->window.getView()->setCenter(sf::Vector2f(128.f, 112.f));
	}
	this->window.update();
	
	this->stateReg[this->state]->update();
}

void Core::render() {
	this->stateReg[this->state]->render();
}

void Core::unload() {
	this->stateReg[this->state]->unload();
}

Core& Core::registerState(GameState _id, states::State* _state) {
	this->stateReg.emplace(_id, _state);
	return *this;
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
		nextState = NONE;
	}
}

void Core::beginRendering() { Core::window.beginRendering(); }
void Core::endRendering() { Core::window.endRendering(); }