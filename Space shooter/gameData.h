#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>

//textures
constexpr auto BackgroundTexturePath = "Textures/background.png";
constexpr auto MenuBackgroundTexturePath = "Textures/menubackground.png";
constexpr auto PlayerTexturePath = "Textures/player.png";
constexpr auto FontPath = "Textures/font.ttf";
constexpr auto PauseTexturePath = "Textures/pause.png";
constexpr auto HeartTexturePath = "Textures/heart.png";
constexpr auto RockTexturePath1 = "Textures/asteroid.png";
constexpr auto RockTexturePath2 = "Textures/asteroid1.png";
constexpr auto RockTexturePath3 = "Textures/asteroid2.png";
constexpr auto RockTexturePath4 = "Textures/asteroid3.png";
constexpr auto RockTexturePath5 = "Textures/asteroid4.png";
constexpr auto BulletTexturePath = "Textures/bullet.png";
constexpr auto ExtraHealthTexturePath = "Textures/extrahealth.png";
constexpr auto ExtraShootingSpeedTexturePath = "Textures/extrashootingspeed.png";
constexpr auto ExplosionTexturePath = "Textures/explosion.png";
constexpr auto MetalTexturePath = "Textures/metal.png";

//sounds
constexpr auto PlayerShootingSound = "Sounds/shoot.wav";
constexpr auto ExplosionSound = "Sounds/explosion.wav";
constexpr auto MenuMovingSoundPath = "Sounds/movingsound.wav";
constexpr auto MenuMusicSoundPath = "Sounds/menusound.wav";
constexpr auto MusicPath = "sounds/music.wav";
constexpr auto PowerUpSoundPath = "Sounds/bonus.wav";
constexpr auto PauseSoundPath = "Sounds/pause.wav";
constexpr auto LevelUpSoundPath = "Sounds/level.wav";
constexpr auto GameOverSoundPath = "Sounds/gameover.wav";
constexpr auto TypingSoundPath = "Sounds/typing.wav";

//output
constexpr auto OutFilePath = "score.score";
//errors
constexpr auto TextureError = "Texture error. Check if path if correct:";
constexpr auto FontError = "Font error. Check if path if correct:";
constexpr auto SoundError = "Sound error. Check if path if correct:";
constexpr auto MusicError = "Music error. Check if path if correct:";

//window settings
constexpr unsigned int FramerateLimit = 60;
constexpr unsigned int res_X = 1280;
constexpr unsigned int res_Y = 800;
constexpr float leftSideDestroyPosition_X = 0.0f;
constexpr float rightSideDestroyPosition_X = 1280.0f;
constexpr float gameAreaTop = 20.f;

//player settings
constexpr float playerSpawnPosition_X = 50.0f;
constexpr float playerSpawnPosition_Y = 400.0f;
constexpr float playerVelocity = 10.0f;
constexpr unsigned int playerHP = 100;
constexpr unsigned int playerMaxHP = 150;
constexpr float playerScale = 0.9f;

//bullets setings
constexpr float bulletVelocity = 15.0f;
constexpr unsigned int  _shootingTimer = 30;

//bonuses settings
constexpr float bonusVelocity = 8.0f;
constexpr unsigned int _extraHP = 50;
constexpr unsigned int _extraSpeed = 5;
constexpr unsigned int _bonusSpawnTimer = 240;

//rocks settings
constexpr float rockSpawnPosition_X = 1400.0f;
constexpr unsigned int _rockSpawnTimer = 20;
constexpr float rockCollisionTestLine = 1100.0f;
constexpr float rockVelocity_X = 5.0f;
constexpr float maxRockVelocity_Y = 1.5f;
constexpr float rockDestroyPosition_X = 0.0f;
constexpr float rockRotation = 0.5f;

//explosion settings
constexpr unsigned int explosionOneFrameTime = 3;
constexpr unsigned int explosionImageCount_X = 4;
constexpr unsigned int explosionImageCount_Y = 4;
constexpr unsigned int explosionImageSize_X = 64;
constexpr unsigned int explosionImageSize_Y = 64;
constexpr float explosionScale = 1.5f;

//score, level & HPbar settings
constexpr unsigned int scoreTextPosition_X = 1180;
constexpr unsigned int scoreTextPosition_Y = 5;
constexpr unsigned int levelTextPosition_X = 640;
constexpr unsigned int levelTextPosition_Y = 5;
constexpr unsigned int levelCharacterSize = 12;
constexpr unsigned int scoreCharacterSize = 12;
constexpr float HPbarPosition_X = 10.0f;
constexpr float HPbarPosition_Y = 10.0f;

//menu & highscore settings
constexpr int numberOfItemsInMenu = 3;
constexpr unsigned int numberOfRowsInHelp = 4;
constexpr unsigned int highscoreCharacterSize = 30;
constexpr unsigned int numberOfRowsInHighscore = 6;
constexpr unsigned int maxNameLength = 10;
