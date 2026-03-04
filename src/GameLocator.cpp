//
// Created by jay on 02/03/2026.
//

#include "GameLocator.h"

#include <iostream>
#include <unistd.h>
#include <pwd.h>

Game GameLocator::game;
std::filesystem::path GameLocator::steamPath;

bool GameLocator::initialised = false;

void GameLocator::initialise() {
    std::cout << "Finding steam path..." << std::endl;
#ifdef __linux__
    initialiseLinuxSteamPath();
#endif
    std::cout << "Found steam path: " << steamPath << std::endl;

    std::cout << "Finding HL2RTX..." << std::endl;
    findHL2RTXPath();
    std::cout << "Found HL2RTX: " << std::filesystem::path (steamPath / game.path) << std::endl;

    initialised = true;
}
void GameLocator::initialiseLinuxSteamPath() {
    const char *homedir = getpwuid(getuid())->pw_dir;
    if (!homedir) {
        throw std::runtime_error("Home environment variable not set!");
    }

    std::filesystem::path tryPath{std::filesystem::path(homedir) / ".steam" / "steam"};
    if (std::filesystem::exists(tryPath)) {
        steamPath = tryPath;
        return;
    }

    tryPath = (std::filesystem::path(homedir) / ".var" / "app" / "com.valvesoftware.Steam"
        / ".local" / "share"/ "com" / "Steam");
    if (std::filesystem::exists(tryPath)) {
        steamPath = tryPath;
    }
}
void GameLocator::findHL2RTXPath() {
    std::filesystem::path tryPath{std::filesystem::path("steamapps") / "common" / "Half-Life 2 RTX"};
    if (std::filesystem::exists(steamPath / tryPath)) {
        game.name = tryPath.filename().string();

        game.path = tryPath;
    }
}

Game* GameLocator::getGame() {
    if (!initialised) {
        throw std::runtime_error("Game Locater not initialised!");
    }
    return &game;
}
