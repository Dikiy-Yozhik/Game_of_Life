#include "game_logic.h"
#include "view.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    int width, height;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;

    Game_Logic game_logic(width, height);

    std::cout << "Enter coordinates of alive cells (x y). Enter -1 -1 to finish input." << std::endl;

    while (true) {
        int x, y;
        std::cout << "Enter coordinates (x y): ";
        std::cin >> x >> y;

        if (x == -1 && y == -1) break;

        if (x >= 0 && x < width && y >= 0 && y < height) {
            game_logic.Get_Field()->Get_Map()[y][x].Set_state(State_Cell::Alive);
        } else {
            std::cout << "Invalid coordinates. Please try again." << std::endl;
        }
    }

    View view;
    view.CreateWindow(width * 15, height * 15 + 50); // Увеличение размера окна

    int generation = 0;
    bool gameOver = false;

    while (view.GetWindow().isOpen()) {
        sf::Event event;
        while (view.GetWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                view.GetWindow().close();
        }

        if (!gameOver) {
            view.GetWindow().clear();
            view.DrawWorld(view.GetWindow(), *game_logic.Get_Field());
            view.GetWindow().display();

            State_Game state = game_logic.Update();
            if (state == State_Game::GameOver || state == State_Game::Stable) {
                gameOver = true;
                if (state == State_Game::GameOver) {
                    std::cout << "\nGame Over!" << std::endl;
                } else if (state == State_Game::Stable) {
                    std::cout << "\nStable configuration reached!" << std::endl;
                }
            }

            generation++;
            sf::sleep(sf::milliseconds(100)); // Задержка между кадрами
        } else {
            view.GetWindow().clear();
            view.DrawWorld(view.GetWindow(), *game_logic.Get_Field());
            view.GetWindow().display();

            sf::sleep(sf::milliseconds(100)); // Маленькая задержка для обновления экрана
        }
    }

    return 0;
}
