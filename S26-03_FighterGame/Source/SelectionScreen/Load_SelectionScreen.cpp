#include "sfml.h"
void SelectionScreen::loadSelectionScreen(sf::RenderWindow& window)
{
    std::string folderPath = "assets/selection screen/";
    std::vector<std::string> OnePaths, TwoPaths, EnterPaths;

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

    if (!OneTextures.empty()) {
        SelectionSprite.setTexture(OneTextures[0]);

        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = OneTextures[0].getSize();
        int cropX = 100;
        SelectionSprite.setTextureRect(sf::IntRect(
            cropX, 0,
            textureSize.x - cropX * 2,
            textureSize.y
        ));

        float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(textureSize.x - cropX * 2);
        float scaleY = static_cast<float>(windowSize.y) / static_cast<float>(textureSize.y);
        SelectionSprite.setScale(scaleX, scaleY);

        sf::FloatRect bounds = SelectionSprite.getLocalBounds();
        SelectionSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        SelectionSprite.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
    }
}