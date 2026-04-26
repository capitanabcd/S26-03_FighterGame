#include "sfml.h"

void Background::loadBackground(sf::RenderWindow& window) {
    std::string folderPath = "assets/background/";
    std::vector<std::string> filePaths;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        std::string path = entry.path().string();
        std::string extension = entry.path().extension().string();

        if (extension == ".jpg" || extension == ".png") {
            filePaths.push_back(path);
        }
    }
    std::sort(filePaths.begin(), filePaths.end());

    for (const auto& path : filePaths) {
        sf::Texture tex;
        if (tex.loadFromFile(path)) {
            backgroundTextures.push_back(std::move(tex));
        }
    }

    if (!backgroundTextures.empty()) {
        backgroundSprite.setTexture(backgroundTextures[0]);
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = backgroundTextures[0].getSize();
        float scaleX = (float)windowSize.x / textureSize.x;
        float scaleY = (float)windowSize.y / textureSize.y;
        backgroundSprite.setScale(scaleX, scaleY);
    }
}