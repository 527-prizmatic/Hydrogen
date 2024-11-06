/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Game window wrapper, coming with many tools to help	 ///
///  with window handling and rendering objects on-screen.	 ///
/// -------------------------------------------------------- ///

#pragma once
#include "toolbox/toolbox.hpp"
#include "View.hpp"

class Window {
private:
	std::unique_ptr<sf::RenderWindow> window; /// Pointer to a linked sf::RenderWindow
	std::unique_ptr<sf::RenderTexture> rTex; /// Pointed to a linked sf::RenderTexture
	std::optional<View*> currentView; /// A series of views that may be configured individually

	std::string title; /// Window title
	bool fullscreen; /// Whether the linked window is in fullscreen
	sf::Vector2u size; /// Size of the linked window, in pixels
	sf::Event evt; /// Event handler
	float aspectRatio; /// Aspect ratio of the linked window

	inline static sf::Sprite renderSpr; /// Used to render the linked render texture onto the linked window

	/// Performs some common initialization operations, such as creating the linked window and render texture.
	void setup();

public:
	/// Default constructor; the produced window will have a resolution of 800x600
	Window();
	/// Window constructor, passing window size as a 2D vector
	Window(sf::Vector2u _size, std::string _title, bool _fullscreen);
	/// Window constructor, passing window size as a pair of integers
	Window(unsigned int _width, unsigned int _height, std::string _title, bool _fullscreen);

	/// Clears the linked window to prepare for the next round of rendering.
	void beginRendering();
	/// Wraps up rendering phase and displays the linked window on-screen.
	void endRendering();
	/// Handles events for the linked window.
	void update();

	/// Renders a drawable object onto the linked render texture.
	void draw(sf::Drawable& _obj);

	bool isOpen() const { return this->window->isOpen(); }
	/// \return Whether the linked window is focused. Used to disable most CPU-consuming and input handling processes when the window runs in the background.
	bool hasFocus() const { return this->window->hasFocus(); }
	/// \return Size of the linked render window, in pixels
	sf::Vector2u getSize() const { return this->size; }

	/// Provided with a 2D vector and a starting aspect ratio, returns the same vector after getting distorted by a factor equal to the linked window's own aspect ratio.
	/// Used for computing view size.
	sf::Vector2f forceAspectRatio(sf::Vector2f _input, float _ratio);

	/// \return The currently active view, or nullptr if there is none
	View* getView();
	/// Changes the window's active view
	inline void setView(View* _v) { this->currentView = _v; }
	/// Unlinks the active view, reverting to rendering on the window's default view
	inline void resetView() { this->currentView.reset(); }
	/// \return Whether the linked window is displayed through a custom view or the window's default internal view
	inline bool hasView() { return this->currentView.has_value(); }
};