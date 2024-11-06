/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  The main function - the entry point of all programs.	 ///
/// -------------------------------------------------------- ///

#include <iostream>
#include <string>

#include "Core.hpp"

int main(int argc, char** argv) {
	Core core;

	while (core.windowIsOpen()) {
		core.init(); // Resource initialization, only if requested
		core.update(); // Tick updates

		core.beginRendering(); // Clears render window
		core.render(); // Rendering
		core.endRendering(); // Displays window on-screen

		core.changeState(); // Handles queued state changes

//		std::cout << random::uniformSum(12, 1.f) << std::endl;
	}
}
