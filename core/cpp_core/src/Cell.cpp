#include "cell.h"

Cell::Cell()
{
    _state = State_Cell::Empty;
}

Cell::Cell(State_Cell state)
{
    _state = state;
}

Cell::~Cell()
{
}

State_Cell Cell::Get_state()
{
    return _state;
}

void Cell::Set_state(State_Cell state)
{
    _state = state;
}

bool Cell::Is_alive()
{
    return _state == State_Cell::Alive;
}