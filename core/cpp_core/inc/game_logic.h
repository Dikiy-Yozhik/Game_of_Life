#pragma once
#include "field.h"
#include <vector>

class Game_Logic
{
private:
    Field* _field;
    Field* _previous_field;

    State_Game Check_State();
    void Rand_location();

public:
    Game_Logic();
    Game_Logic(int rows, int cols);
    Game_Logic(int rows, int cols, std::vector<Point> start_location);
    ~Game_Logic();

    Field* Get_Field();
    int Get_Rows();
    int Get_Cols();

    State_Game Update();
};