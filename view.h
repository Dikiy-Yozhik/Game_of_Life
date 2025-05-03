#pragma once
#include <SFML/Graphics.hpp>
#include "field.h"

class View {
public:
    void CreateWindow(int width, int height);
    void DrawWorld(sf::RenderWindow& window, Field& map);
    sf::RenderWindow& GetWindow() { return window; }
private:
    sf::RenderWindow window;
};

