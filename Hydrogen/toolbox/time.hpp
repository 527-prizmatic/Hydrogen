/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///						 == FILE NAME ==					 ///
///							time.hpp						 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Simple SFML-based time utilities.						 ///
/// -------------------------------------------------------- ///


#pragma once
#include "toolbox.hpp"

namespace tutil {
	/// Restarts the internal clock.
	void restart();

	/// \return Time elapsed since last tutil::restart() call, in seconds
	float getDelta();
}