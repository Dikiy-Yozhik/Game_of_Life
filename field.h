#pragma once
#include "cell.h"
#include "enums.h"

class Field
{
private:
    Cell** _map;
    int _rows;
    int _columns;

    int Living_Cells_Range(int row_from, int row_to, int col_from, int col_to, Point current);

public:
    Field();
    Field(int rows, int cols);
    ~Field();

    int Get_rows();
    int Get_cols();
    Cell** Get_Map();

    int Living_Cells_Around(Point point);
};