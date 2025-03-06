#include <ctime>
#include <iostream>
#include <stdlib.h>
#include "game_logic.h"

// --- Support ---
int Game_Logic::Get_Cols() {
    return _field->Get_cols();
}

int Game_Logic::Get_Rows() {
    return _field->Get_rows();
}

void Game_Logic::Rand_location() {
    int count_alive = rand() % (Get_Cols() * Get_Rows() - 1) + 1;

    Point point;
    for (int i = 0; i < count_alive; i++) {
        point.X = rand() % Get_Rows();
        point.Y = rand() % Get_Cols();
        _field->Get_Map()[point.X][point.Y].Set_state(State_Cell::Alive);
    }
}

// --- Con/De-structor ---
Game_Logic::Game_Logic() {
    srand(time(NULL));
    _field = new Field(10, 10);
    _previous_field = new Field(*_field);
    Rand_location();
}

Game_Logic::Game_Logic(int rows, int cols) {
    srand(time(NULL));
    _field = new Field(rows, cols);
    _previous_field = new Field(*_field);
    //Rand_location();
}

Game_Logic::Game_Logic(int rows, int cols, std::vector<Point> start_location) {
    _field = new Field(rows, cols);
    _previous_field = new Field(*_field);
    for (auto point : start_location) {
        if (point.X >= 0 && point.X < rows && point.Y >= 0 && point.Y < cols) {
            _field->Get_Map()[point.X][point.Y].Set_state(State_Cell::Alive);
        }
    }
}

Game_Logic::~Game_Logic() {
    delete _field;
    delete _previous_field;
}

Field* Game_Logic::Get_Field() {
    return _field;
}

// --- Logic ---
State_Game Game_Logic::Check_State() {
    int count_alive = 0;
    bool is_stable = true;

    for (int i = 0; i < Get_Rows(); i++) {
        for (int j = 0; j < Get_Cols(); j++) {
            if (_field->Get_Map()[i][j].Is_alive()) {
                count_alive++;
            }
            if (_field->Get_Map()[i][j].Is_alive() != _previous_field->Get_Map()[i][j].Is_alive()) {
                is_stable = false;
            }
        }
    }

    if (count_alive == 0) {
        return State_Game::GameOver;
    }

    if (is_stable) {
        return State_Game::Stable;
    }

    return State_Game::Run;
}

State_Game Game_Logic::Update() {
    Field* temp_field = new Field(Get_Rows(), Get_Cols());

    for (int i = 0; i < Get_Rows(); i++) {
        for (int j = 0; j < Get_Cols(); j++) {
            int count_alive = _field->Living_Cells_Around(Point(i, j));

            if (count_alive == 3 || (count_alive == 2 && _field->Get_Map()[i][j].Is_alive())) {
                temp_field->Get_Map()[i][j].Set_state(State_Cell::Alive);
            } else {
                temp_field->Get_Map()[i][j].Set_state(State_Cell::Empty);
            }
        }
    }

    delete _previous_field;
    _previous_field = new Field(*_field);
    delete _field;
    _field = temp_field;

    return Check_State();
}