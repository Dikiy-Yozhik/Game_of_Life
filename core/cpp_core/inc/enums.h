#pragma once

enum State_Cell
{
    Empty,
    Alive
};

enum State_Game
{
    Run,
    GameOver,
    Stable
};

struct Point
{
    int X, Y;

    Point(){
        X = 0;
        Y = 0;
    }

    Point(int x, int y){
        X = x;
        Y = y;
    }
};