class SelectionScreen {
public:
    SelectionScreen();

    void loadSelectionScreen(sf::RenderWindow& window);
    void Load_IdleTextures();
    void HandleInput(sf::Event& event);
    void UpdateSelectionScreen(sf::RenderWindow& window);
    void renderSelectionScreen(sf::RenderWindow& window);

    bool isSelecting;
    int player1Choice;
    int player2Choice;

private:
    void NormalizeCharacter(sf::Sprite& character);

    sf::Sprite SelectionSprite;
    sf::Sprite Character1;
    sf::Sprite Character2;

    std::vector<sf::Texture> OneTextures, TwoTextures, EnterTextures;
    std::vector<sf::Texture> C1, C2, C3, C4, C5;

    bool isEnterPlaying, isOnePlaying, isTwoPlaying;
    bool player1Selected, player2Selected;
    bool player2Active;

    int EnterFrames, OneFrames, TwoFrames;
    int index1, index2;
    int frames1, frames2;
    int selectingFor;

    sf::Clock enterClock;
    sf::Clock oneClock;
    sf::Clock twoClock;
    sf::Clock idleClock1;
    sf::Clock idleClock2;

    float p1CharX = 0.25f;
    float p1CharY = 0.768f;
    float p2CharX = 0.71f;
    float p2CharY = 0.768f;
};