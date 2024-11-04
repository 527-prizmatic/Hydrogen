/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  View wrapper, for easily manipulating 2D cameras.		 ///
/// -------------------------------------------------------- ///

#pragma once
#include "toolbox/toolbox.hpp"

class Window;

class View {
private:
	sf::View view; /// Linked sf::View object
	sf::Vector2f center; /// Absolute coordinates of the center of the view's viewport
	sf::Vector2f size; /// Size of the view's viewport, in pixels

public:
	/// Default constructor; the produced view will have a viewport of 800x600
	View();
	/// Produces a view whose viewport is computed according to the passed window's size.
	View(const Window& _w);
	/// Produces a view based on its viewport's size. Will be centered on (0, 0).
	View(sf::Vector2f _size);
	/// Produces a view based on its viewport's top-left and bottom-right corners.
	View(sf::Vector2f _tl, sf::Vector2f _br);

	/// Resizes the view's viewport.
	const void setSize(sf::Vector2f _size);
	/// Moves the view's center.
	const void setCenter(sf::Vector2f _center);
	/// Sets the view's corners.
	const void setCorners(sf::Vector2f _tl, sf::Vector2f _br);

	const sf::View& getView() { return this->view; }
};

