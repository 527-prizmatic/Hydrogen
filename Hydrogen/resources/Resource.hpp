/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Common interface for external multimedia resources,	 ///
///  such as textures, sounds, and typefaces.				 ///
/// -------------------------------------------------------- ///

#pragma once
#include "../toolbox/toolbox.hpp"

/// Prototype resource storage node.
/// An extension to this class must always contain a SFML-managed resource, such as a sf::Texture or sf::Sound.
class Resource {
private:
	std::string id; /// String ID for quick lookup
public:

	/// Creates a completely empty resource.
	Resource() = delete;
	/// Creates a resource from a file path and a string ID.
	Resource(std::string _path, std::string _id) = delete;

	/// Initializes the resource buffer and preloads eventual placeholder resources.
	static void preinit() = delete;
	/// Preloads a resource from the given path and into the corresponding resource buffer.
	static void preload(std::string _path, std::string _id) = delete;
	/// Unloads the resource with the given string ID from the corresponding resource buffer.
	static bool unload(std::string& _id) = delete;
	/// Completely empties the corresponding resource buffer.
	static bool clear() = delete;

	/// Produces a full resource file path based on the file's name.
	inline static std::string path(std::string _path) { return "../assets/" + _path; }
};