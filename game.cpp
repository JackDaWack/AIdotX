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
    
    //victory checker methods
    bool check_rows(char player);
    bool check_cols(char player);
    bool check_diags(char player);
    bool victory_check(char player);
    //getters and setters
    vector<vector<char>> * get_board(){return board;}
    void set_board(vector<vector<char>> * new_board){board = new_board;}
    char get_at_position(int i, int j){return board->at(i).at(j);}
    void set_at_position(int i, int j, char mark){board->at(i).at(j) = mark;}
};

class ai_player
{
    private:
    //data
    public:
    ai_player();
    ~ai_player();

    //ai marks a spot on the gameboard as an 'X'.
    void move_to();
    //ai considers its options.
    void think();
};

