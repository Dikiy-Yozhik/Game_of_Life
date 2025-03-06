#include "game_logic.h"
#include "view.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void Menu(int& act) {
    cout << "Choose the action: " << endl
         << "0 - Exit" << endl
         << "1 - Continue" << endl
         << "Your choice: ";

    cin >> act;
}

int main() {
    Game_Logic game_logic;
    View view;

    int act = 0;
    int generation = 0;

    while (1) {
        //system(CLEAR); 
        cout << "=== Generation " << generation << " ===" << endl;
        view.Print_World(*game_logic.Get_Field());
        cout << " =================== " << endl;

        Menu(act);
        if (act == 0){
            cout << "\nGame Over!" << endl;
            break;
        }

        generation++;
        State_Game state = game_logic.Update();
        if(state == State_Game::GameOver || state == State_Game::Stable){
            //system(CLEAR);
            if(state == State_Game::GameOver){
                cout << "\nGame Over!" << endl;
            } 
            else if(state == State_Game::Stable){
                cout << "\nStable configuration reached!" << endl;
            }
            break;
        }

        cout << endl;
    }

    cout << " === Last generation " << generation << " ===" << endl;
    view.Print_World(*game_logic.Get_Field());
    cout << "=================" << endl;

    return 0;
}