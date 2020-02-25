#include "resourcemanager.h"

sf::Texture & resourceManager::getTexture(const std::string& path)
{
	auto found = textures.find(path);
	if (found == textures.end())
	{
		auto & texture = textures[path];
		if (!texture.loadFromFile(path))
		{
			std::string error = TextureError + path;
			throw error;
		}
		texture.setSmooth(true);
		return texture;
	}
	else
	{
		return found->second;
	}
}

sf::Font & resourceManager::getFont(const std::string& path)
{
	auto found = fonts.find(path);
	if (found == fonts.end())
	{
		auto & font = fonts[path];
		if (!font.loadFromFile(path))
		{
			std::string error = FontError + path;
			throw error;
		}
		return font;
	}
	else
	{
		return found->second;
	}
}

sf::SoundBuffer & resourceManager::getSound(const std::string& path)
{
	auto found = sounds.find(path);
	if (found == sounds.end())
	{
		auto & sound = sounds[path];
		if (!sound.loadFromFile(path))
		{
			std::string error = SoundError + path;
			throw error;
		}
		return sound;
	}
	else
	{
		return found->second;
	}
}

sf::Music & resourceManager::getMusic(const std::string& path)
{
	auto found = music.find(path);
	if (found == music.end())
	{
		auto & MyMusic = music[path];
		if (!MyMusic.openFromFile(path))
		{
			std::string error = MusicError + path;
			throw error;
		}
		MyMusic.setLoop(true);
		return MyMusic;
	}
	else
	{
		return found->second;
	}
}
