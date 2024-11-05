/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Custom random number generators.						 ///
/// -------------------------------------------------------- ///

#pragma once
#include "toolbox.hpp"

namespace random {
	/// \return A uniformly random signed 32-bit integer
	int int_32();

	/// \return A uniformly random unsigned 32-bit integer
	unsigned int uint_32();

	/// \return A uniformly random signed 32-bit integer between _min and _max
	int range(int _min, int _max);

	/// Return Uniformly random floating-point number between 0 and 1
	float unit();

	/// Return Uniformly random floating-point number between 0 and _max
	float unit(float _max);

	/// Return Uniformly random floating-point number between _min and _max
	float unit(float _min, float _max);

	/// \return true with a probability of _chance; false otherwise
	bool chance(float _chance);

	/// \param _count - Number of dice
	/// \param _die - Number of sides for each die
	/// \return The result of an ideal dice roll
	int diceroll(int _count, int _die);

	/// Computes random floating-point numbers using the Irwin-Hall distribution.
	/// This distribution computes a sum of random values between 0 and 1 and adjusts it based on the requested mean.
	/// Its variance is _vals / 12.
	float uniformSum();

	/// Computes random floating-point numbers using the Irwin-Hall distribution.
	/// This distribution computes a sum of random values between 0 and 1 and adjusts it based on the requested mean.
	/// Its variance is _vals / 12.
	float uniformSum(float _mean);

	/// Computes random floating-point numbers using the Irwin-Hall distribution.
	/// This distribution computes a sum of random values between 0 and 1 and adjusts it based on the requested mean.
	/// Its variance is _vals / 12.
	float uniformSum(int _vals, float _mean);
}