#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include "gameData.h"

class resourceManager
{
private:
	std::unordered_map<std::string, sf::Texture> textures;
	std::unordered_map<std::string, sf::Font> fonts;
	std::unordered_map<std::string, sf::SoundBuffer> sounds;
	std::unordered_map<std::string, sf::Music> music;
public:
	resourceManager() = default;
	~resourceManager() = default;
	sf::Texture& getTexture(const std::string& path);
	sf::Font& getFont(const std::string& path);
	sf::SoundBuffer& getSound(const std::string& path);
	sf::Music& getMusic(const std::string& path);
};

