#include "view.h"

void View::CreateWindow(int width, int height) {
    window.create(sf::VideoMode(width, height), "Game of Life");
    window.setFramerateLimit(60);
    window.requestFocus(); 
}

void View::DrawWorld(sf::RenderWindow& window, Field& map) {
    int rows = map.Get_rows();
    int cols = map.Get_cols();

    // Рассчитываем размер клетки так, чтобы поле занимало 70% окна
    float scaleFactor = std::min(
        (window.getSize().x * 0.9f) / cols,
        (window.getSize().y * 0.9f) / rows
    );

    // Рассчитываем позицию поля в окне
    int offsetX = (window.getSize().x - cols * scaleFactor) / 2;
    int offsetY = (window.getSize().y - rows * scaleFactor) / 2;

    window.clear(sf::Color::White); // Белый фон

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::RectangleShape cell(sf::Vector2f(scaleFactor, scaleFactor)); // Размер клетки

            if (map.Get_Map()[i][j].Is_alive()) {
                cell.setFillColor(sf::Color::Green); // Живая клетка
            } else {
                cell.setFillColor(sf::Color::White); // Мертвая клетка
            }

            cell.setOutlineThickness(1); // Толщина рамки
            cell.setOutlineColor(sf::Color::Black); // Цвет рамки

            cell.setPosition(offsetX + j * scaleFactor, offsetY + i * scaleFactor); // Позиция клетки
            window.draw(cell);
        }
    }

    window.display();
}



