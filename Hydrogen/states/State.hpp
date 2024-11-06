/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///						 == FILE NAME ==					 ///
///							State.hpp						 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Template class for game states. All gamestates created	 ///
///  with this blueprint should be registered at their		 ///
///  respective Core's preinitialization phase.				 ///
/// -------------------------------------------------------- ///

#pragma once
#include "../toolbox/toolbox.hpp"

class Core;

namespace states {
	/// Interface for gamestates
	class State {
	protected:
		Core* core;
	public:
		/// Functions to be called when initializing this game state
		virtual void init() = 0;
		/// Functions to be called on each frame when this game state is up
		virtual void update() = 0;
		/// Functions linked to rendering for this game state
		virtual void render() = 0;
		/// Functions related to data destruction and garbage collection when terminating this game state
		virtual void unload() = 0;
	};
}