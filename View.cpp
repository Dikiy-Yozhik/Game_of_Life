#include "view.h"

void View::CreateWindow(int width, int height) {
    window.create(sf::VideoMode(width, height), "Game of Life");
    window.setFramerateLimit(60);
}

void View::DrawWorld(sf::RenderWindow& window, Field& map) {
    sf::RectangleShape cell(sf::Vector2f(10, 10)); // Размер клетки

    for (int i = 0; i < map.Get_rows(); ++i) {
        for (int j = 0; j < map.Get_cols(); ++j) {
            if (map.Get_Map()[i][j].Is_alive()) {
                cell.setFillColor(sf::Color::White); // Живая клетка
            } else {
                cell.setFillColor(sf::Color::Black); // Мертвая клетка
            }

            cell.setPosition(j * 10, i * 10); // Позиция клетки
            window.draw(cell);
        }
    }
}

