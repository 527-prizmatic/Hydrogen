/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Auxiliary mathematics library allowing to perform		 ///
///  linear algebra and trigonometry on 2D vector spaces,	 ///
///  as well as simplifying a few complex functions.		 ///
/// -------------------------------------------------------- ///

#pragma once
#include "toolbox.hpp"

/// Circle constant, approximately 3.142
extern const double pi;
/// Exponential constant, approximately 2.718
extern const double euler;
/// Golden ratio, approximately 1.618
extern const double phi;

/// Quick square function
template <typename T> T pow2(T _a) { return _a * _a; }
/// Quick cube function
template <typename T> T pow3(T _a) { return _a * _a * _a; }
/// Quick fourth power function
template <typename T> T pow4(T _a) { return _a * _a * _a * _a; }

/// Quick power function for integer exponents, because the implementation of pow() is horrendous
int powi(int _a, int _exp);
/// Quick power function for integer exponents, because the implementation of pow() is horrendous
float powi(float _a, int _exp);
/// Quick power function for integer exponents, because the implementation of pow() is horrendous
double powi(double _a, int _exp);

/// Clamps a value between two bounds, both included.
float clamp(float _x, float _lower, float _upper);

namespace vect {
	/// Computes the magnitude of a vector.
	/// As this function requires an expensive square root computation, it should be avoided unless truly necessary.
	float magnitude(sf::Vector2f _v);
	/// Computes the magnitude of a vector.
	/// As this function requires an expensive square root computation, it should be avoided unless truly necessary.
	float magnitude(sf::Vector2i _v);
	/// Computes the magnitude of a vector.
	/// As this function requires an expensive square root computation, it should be avoided unless truly necessary.
	float magnitude(sf::Vector2u _v);

	/// Computes the squared magnitude of a vector.
	/// As it does not require an expensive square root computation, it should be used whenever possible, for the sake of performance.
	float magnitude2(sf::Vector2f _v);
	/// Computes the squared magnitude of a vector.
	/// As it does not require an expensive square root computation, it should be used whenever possible, for the sake of performance.
	float magnitude2(sf::Vector2i _v);
	/// Computes the squared magnitude of a vector.
	/// As it does not require an expensive square root computation, it should be used whenever possible, for the sake of performance.
	float magnitude2(sf::Vector2u _v);

	/// Normalizes a vector, dividing it by its magnitude.
	sf::Vector2f normalize(sf::Vector2f _v);
	/// Normalizes a vector, dividing it by its magnitude.
	sf::Vector2f normalize(sf::Vector2i _v);
	/// Normalizes a vector, dividing it by its magnitude.
	sf::Vector2f normalize(sf::Vector2u _v);
}