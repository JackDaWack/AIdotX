#include <vector>

using namespace std;

class game_board
{
private:
    vector<vector<char>> * board; 
public:
    game_board(){
        //Gameboard initialization.
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board->at(i).at(j) = '#';
            }
        }
    }
    ~game_board();
    
    bool check_rows(char player);
    bool check_cols(char player);
    bool check_diags(char player);
    bool victory_check(char player);
};

