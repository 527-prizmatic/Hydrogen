#pragma once
#include "toolbox.hpp"

namespace tutil {
	/// Restarts the internal clock.
	void restart();

	/// \return Time elapsed since last tutil::restart() call, in seconds
	float getDelta();
}