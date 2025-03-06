#include <algorithm>
#include "field.h"

int Field::Living_Cells_Range(int row_from, int row_to, int col_from, int col_to, Point current)
{
    int count_alive = 0;

    for(int i = row_from; i <= row_to; i++){
        for(int j = col_from; j <= col_to; j++){
            if(i == current.X && j == current.Y)
                continue;
            if(_map[i][j].Is_alive())
                count_alive++;
        }
    }

    return count_alive;
}

Field::Field(const Field& other) {
    _rows = other._rows;
    _columns = other._columns;

    _map = new Cell* [_rows];
    for(int i = 0; i < _rows; i++) {
        _map[i] = new Cell[_columns];
        for(int j = 0; j < _columns; j++) {
            _map[i][j] = other._map[i][j]; // Копирование состояния клеток
        }
    }
}


Field::Field()
{
    _rows = 5;
    _columns = 5;

    _map = new Cell* [_rows];
    for(int i = 0; i < _rows; i++)
        _map[i] = new Cell[_columns];
}

Field::Field(int rows, int cols)
{
    _rows = rows;
    _columns = cols;

    _map = new Cell* [_rows];
    for(int i = 0; i < _rows; i++)
        _map[i] = new Cell[_columns];
}
    
Field::~Field()
{
    for(int i = 0; i < _rows; i++)
        delete[] _map[i];
    delete[] _map;
}

int Field::Get_rows()
{
    return _rows;
}
    
int Field::Get_cols()
{
    return _columns;
}

Cell** Field::Get_Map()
{
    return _map;
}

int Field::Living_Cells_Around(Point point) {
    int row_from = std::max(0, point.X - 1);
    int row_to = std::min(_rows - 1, point.X + 1);
    int col_from = std::max(0, point.Y - 1);
    int col_to = std::min(_columns - 1, point.Y + 1);

    return Living_Cells_Range(row_from, row_to, col_from, col_to, point);
}