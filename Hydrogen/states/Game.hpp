/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///						 == FILE NAME ==					 ///
///							Game.hpp						 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Example implementation of the gamestate blueprint.		 ///
/// -------------------------------------------------------- ///

#pragma once
#include "../toolbox/toolbox.hpp"
#include "State.hpp"

namespace states {
	class Game : public State {
	private:
		Core* core;
	public:
		Game(Core* _core);
		void init();
		void update();
		void render();
		void unload();
	};
}