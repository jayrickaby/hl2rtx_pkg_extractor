//
// Created by jay on 02/03/2026.
//

#ifndef HL2RTX_PKG_EXTRACTOR_GAMELOCATOR_H
#define HL2RTX_PKG_EXTRACTOR_GAMELOCATOR_H
#include <filesystem>
#include <map>


class GameLocator {
    public:
    GameLocator() = default;
    ~GameLocator() = default;

    static void initialise();
private:
    static void initialiseLinuxSteamPath();

    static std::map<std::string, std::filesystem::path> games;
    static std::filesystem::path steamPath;
};


#endif //HL2RTX_PKG_EXTRACTOR_GAMELOCATOR_H