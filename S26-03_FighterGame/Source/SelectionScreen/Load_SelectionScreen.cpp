#include "sfml.h"
void SelectionScreen ::loadSelectionScreen() 
{
    std::string folderPath = "assets/selection screen/";
    std::vector<std::string> OnePaths,TwoPaths,EnterPaths;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        std::string path = entry.path().string();
        std::string filename = entry.path().filename().string();

        if (entry.path().extension() == ".jpg") {
            if (filename.find("one") != std::string::npos)
                OnePaths.push_back(path);
            else if (filename.find("two") != std::string::npos)
				TwoPaths.push_back(path);
            else if (filename.find("enter") != std::string::npos)
                EnterPaths.push_back(path);
        }
    }
    std::sort(OnePaths.begin(), OnePaths.end());
    std::sort(EnterPaths.begin(), EnterPaths.end());
    std::sort(TwoPaths.begin(), TwoPaths.end());

    for (const auto& path : OnePaths) {
        OneTextures.emplace_back().loadFromFile(path);
    }

    for (const auto& path : EnterPaths) {
        EnterTextures.emplace_back().loadFromFile(path);
    }

    for (const auto& path : TwoPaths) {
        TwoTextures.emplace_back().loadFromFile(path);
    }
}