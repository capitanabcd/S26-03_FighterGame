#include "sfml.h"
void cell::LoadTexture(std::vector<sf::Texture>& HeavyAttack, std::vector<sf::Texture>& Idle, std::vector<sf::Texture>& Movement, std::vector<sf::Texture>& Stagger, std::vector<sf::Texture>& beam, std::vector<sf::Texture>& ranged, std::vector<sf::Texture>& basic)
{
    std::string folderPath = "assets/Cell/";
    std::vector<std::string> idlePaths, movementPaths, heavyPaths, staggerPaths, beamPaths, rangedPaths, basicPaths;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        std::string path = entry.path().string();
        std::string filename = entry.path().filename().string();

        if (entry.path().extension() == ".png") {
            if (filename.find("Idle") != std::string::npos)
                idlePaths.push_back(path);
            else if (filename.find("Movement") != std::string::npos)
                movementPaths.push_back(path);
            else if (filename.find("stagger") != std::string::npos)
                staggerPaths.push_back(path);
            else if (filename.find("HeavyAttack") != std::string::npos)
                heavyPaths.push_back(path);
            else if (filename.find("beam") != std::string::npos)
                beamPaths.push_back(path);
            else if (filename.find("ranged") != std::string::npos)
                rangedPaths.push_back(path);
            else if (filename.find("BasicAttack") != std::string::npos)
                basicPaths.push_back(path);
        }
    }
    std::sort(idlePaths.begin(), idlePaths.end());
    std::sort(movementPaths.begin(), movementPaths.end());
    std::sort(staggerPaths.begin(), staggerPaths.end());
    std::sort(heavyPaths.begin(), heavyPaths.end());
    std::sort(beamPaths.begin(), beamPaths.end());
    std::sort(rangedPaths.begin(), rangedPaths.end());
    std::sort(basicPaths.begin(), basicPaths.end());

    for (const auto& path : idlePaths) {
        Idle.emplace_back().loadFromFile(path);
    }

    for (const auto& path : movementPaths) {
        Movement.emplace_back().loadFromFile(path);
    }

    for (const auto& path : staggerPaths) {
        Stagger.emplace_back().loadFromFile(path);
    }

    for (const auto& path : heavyPaths) {
        HeavyAttack.emplace_back().loadFromFile(path);
    }
    for (const auto& path : beamPaths) {
        beam.emplace_back().loadFromFile(path);
    }
    for (const auto& path : rangedPaths) {
        ranged.emplace_back().loadFromFile(path);
    }
    for (const auto& path : basicPaths) {
        basic.emplace_back().loadFromFile(path);
    }
}