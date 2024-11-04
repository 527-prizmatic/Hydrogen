/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  The core of an all-purpose toolbox, usable as a single	 ///
///  include to instantly get all individual modules.		 ///
/// -------------------------------------------------------- ///


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <optional>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#include "time.hpp"
#include "random.hpp"
#include "custom_math.hpp"
#include "interpolation.hpp"
#include "../controls/Controls.hpp"

/// Control handlers
namespace ctrl {
	/// Button states for control handlers
	typedef enum ButtonState {
		IDLE,
		CLICK,
		HOLD,
		RELEASE
	} ButtonState;
}