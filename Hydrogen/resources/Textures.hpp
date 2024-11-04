#pragma once
#include "../toolbox/toolbox.hpp"

/// Data storage node for the texture buffer
class Texture {
private:
	sf::Texture tex; /// Texture stored within
	std::string id; /// String ID for quick lookup

	static sf::Texture placeholder; /// Placeholder texture to replace unloaded or erroneous textures
	static std::list<Texture*> texList; /// Texture buffer
public:
	/// Creates a completely empty texture.
	Texture(); 
	/// Creates a texture from a file path and a string ID.
	Texture(std::string _path, std::string _id);
	/// Creates a texture from an existing sf::Texture and a string ID.
	/// The given sf::Texture is copied into the data holder, so it can be safely deleted afterwards.
	Texture(sf::Texture& _tex, std::string _id);

	/// Initializes the texture buffer and preloads the placeholder texture.
	static void init();
	/// Preloads a texture from the given path and into the texture buffer.
	static void preload(std::string _path, std::string _id);
	/// Unloads the texture with the given string ID from the texture buffer.
	static bool unload(std::string& _id);
	/// Completely empties the texture buffer.
	static bool clear();

	/// \return A texture corresponding to the given string ID, or a placeholder if none is found
	static const sf::Texture& getTexture(std::string _id);
};