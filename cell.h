#pragma once
#include "enums.h"

class Cell
{
private:
    State_Cell _state;

public:
    Cell();
    Cell(State_Cell state);
    ~Cell();

    State_Cell Get_state();
    void Set_state(State_Cell state);
    bool Is_alive();
};