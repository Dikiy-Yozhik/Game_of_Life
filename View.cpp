#include "view.h"

void View::Print_World(Field& map)
{
    for(int i = 0; i < map.Get_rows(); i++){
        for(int j = 0; j < map.Get_cols(); j++){
            if(map.Get_Map()[i][j].Is_alive()){
                cout << "l ";
            }
            else{
                cout << "e ";
            }
        }
        cout << endl;
    }
}