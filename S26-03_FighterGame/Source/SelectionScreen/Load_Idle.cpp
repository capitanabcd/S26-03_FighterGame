#include "sfml.h"
void SelectionScreen::Load_IdleTextures()
{
    std::string folderPath = "assets/cell/";
    std::vector<std::string> idlePaths;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        std::string path = entry.path().string();
        std::string filename = entry.path().filename().string();

        if (entry.path().extension() == ".png") {
            if (filename.find("cell") != std::string::npos)
                idlePaths.push_back(path);
        }
    }
    std::sort(idlePaths.begin(), idlePaths.end());
    for (const auto& path : idlePaths) {
        C1.emplace_back().loadFromFile(path);
    }
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    folderPath = "assets/goku/";
    idlePaths.clear();

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        std::string path = entry.path().string();
        std::string filename = entry.path().filename().string();

        if (entry.path().extension() == ".png") {
            if (filename.find("Idle") != std::string::npos)
                idlePaths.push_back(path);
        }
    }
    std::sort(idlePaths.begin(), idlePaths.end());
    for (const auto& path : idlePaths) {
        C2.emplace_back().loadFromFile(path);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    folderPath = "assets/freeza/";
    idlePaths.clear();
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        std::string path = entry.path().string();
        std::string filename = entry.path().filename().string();

        if (entry.path().extension() == ".png") {
            if (filename.find("Idle") != std::string::npos)
                idlePaths.push_back(path);
        }
    }
    std::sort(idlePaths.begin(), idlePaths.end());
    for (const auto& path : idlePaths) {
        C3.emplace_back().loadFromFile(path);
    }
}