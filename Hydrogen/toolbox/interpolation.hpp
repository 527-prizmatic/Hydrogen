/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Library of interpolators, allowing to perform various	 ///
///  types of interpolation on multiple data types.			 ///
///  Obviously, these only support arithmetic types and		 ///
///  their derivatives, such as sf::Colors.					 ///
/// -------------------------------------------------------- ///

#pragma once
#include "toolbox.hpp"

#define ITP(a, b, t) (((b) - (a)) * (t) + (a))

namespace itp {
	/// Scalar interpolation
	template <typename T> T scalar(T _a, T _b, float _t, float _method(float _x)) {
		static_assert(std::is_arithmetic_v<T>, "Attempted interpolation with non-arithmetic values");
		float it = _method(_t);
		return ITP(_a, _b, it);
	}

	/// Two-dimensional vector interpolation
	template <typename T> sf::Vector2<T> vector(sf::Vector2<T> _a, sf::Vector2<T> _b, float _t, float _method(float _x)) {
		static_assert(std::is_arithmetic_v<T>, "Attempted interpolation with non-arithmetic values");
		float it = _method(_t);
		return sf::Vector2<T>(ITP(_a.x, _b.x, it), ITP(_a.y, _b.y, it));
	}

	/// sf::Color interpolation
	sf::Color color(sf::Color _a, sf::Color _b, float _t, float _method(float _x));

	namespace formula {
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return 1 if x >= 0.5, 0 otherwise
		float Nearest(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return x
		float Linear(float _x);

		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return x^2
		float Square(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return x^3
		float Cubic(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return x^4
		float Quartic(float _x);

		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return 1 - (x-1)^2
		float InvSquare(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return 1 - (x-1)^3
		float InvCubic(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return 1 - (x-1)^4
		float InvQuartic(float _x);

		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return -2x^3 + 3x^2
		float Smooth(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return 6x^5 - 15x^4 + 10x^3
		float Smoother(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return -20x^7 + 70x^6 - 85x^5 + 35x^4
		float Smoothest(float _x);
		/// Nearest-neighbor interpolator, clamped between 0 and 1.
		/// \return 70x^9 - 315x^8 + 540x^7 - 420x^6 + 126x^5
		float Smoothester(float _x);
	}
}