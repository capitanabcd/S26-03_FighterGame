#include "sfml.h"
void SelectionScreen ::loadSelectionScreen() 
{
    std::string folderPath = "assets/selection screen/";
    std::vector<std::string> ArrowPaths,EnterPaths,SelectionPaths;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        std::string path = entry.path().string();
        std::string filename = entry.path().filename().string();

        if (entry.path().extension() == ".jpg") {
            if (filename.find("Arrow") != std::string::npos)
                ArrowPaths.push_back(path);
            else if (filename.find("enter") != std::string::npos)
                EnterPaths.push_back(path);
            else if (filename.find("selection") != std::string::npos)
				SelectionPaths.push_back(path);
        }
    }
    std::sort(ArrowPaths.begin(), ArrowPaths.end());
    std::sort(EnterPaths.begin(), EnterPaths.end());
    std::sort(SelectionPaths.begin(), SelectionPaths.end());

    for (const auto& path : ArrowPaths) {
        ArrowTextures.emplace_back().loadFromFile(path);
    }

    for (const auto& path : EnterPaths) {
        EnterTextures.emplace_back().loadFromFile(path);
    }

    for (const auto& path : SelectionPaths) {
        SelectionTextures.emplace_back().loadFromFile(path);
    }
}