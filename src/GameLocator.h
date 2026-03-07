//
// Created by jay on 02/03/2026.
//

#ifndef HL2RTX_PKG_EXTRACTOR_GAMELOCATOR_H
#define HL2RTX_PKG_EXTRACTOR_GAMELOCATOR_H
#include <filesystem>
#include <map>

struct Game {
    std::string name;
    std::filesystem::path path;
};

class GameLocator {
    public:
    GameLocator() = default;
    ~GameLocator() = default;

    static void initialise();

    // Getters
    static Game* getGame();
    static std::filesystem::path getSteamPath();

private:
    static void initialiseLinuxSteamPath();
    static void findHL2RTXPath();

    static Game game;
    static std::filesystem::path steamPath;

    static bool initialised;
};


#endif //HL2RTX_PKG_EXTRACTOR_GAMELOCATOR_H