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
		core.init();
		core.update();

		core.beginRendering();
		core.render();
		core.endRendering();

		core.changeState();
	}
}
