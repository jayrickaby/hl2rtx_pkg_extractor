//
// Created by jay on 02/03/2026.
//

#include "GameLocator.h"

#include <iostream>
#include <unistd.h>
#include <pwd.h>

std::map<std::string, std::filesystem::path> GameLocator::games;
std::filesystem::path GameLocator::steamPath;

void GameLocator::initialise() {
#ifdef __linux__
    initialiseLinuxSteamPath();
#endif
    std::cout << "Found steam path: " << steamPath.string() << std::endl;
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
