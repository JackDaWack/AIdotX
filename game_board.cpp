#include <vector>

using namespace std;

class game_board
{
private:
    vector<vector<char>> * board; 
public:
    game_board(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board[i][j] = '#';
            }
        }
    }
    ~game_board();
};

