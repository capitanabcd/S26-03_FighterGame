#include "sfml.h"
void freeza::LoadTexture(std::vector<sf::Texture>& HeavyAttack, std::vector<sf::Texture>& Idle, std::vector<sf::Texture>& Movement, std::vector<sf::Texture>& Stagger)
{
    std::string folderPath = "freeza/";
    std::vector<std::string> idlePaths, movementPaths, heavyPaths, staggerPaths;

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
        }
    }
    std::sort(idlePaths.begin(), idlePaths.end());
    std::sort(movementPaths.begin(), movementPaths.end());
    std::sort(staggerPaths.begin(), staggerPaths.end());
    std::sort(heavyPaths.begin(), heavyPaths.end());

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
    
}