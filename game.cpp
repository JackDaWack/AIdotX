#include <vector>
#include <random>
#include <ctime> 
#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

class game_board
{
private:
    vector<vector<char>>* board = new vector<vector<char>>(3, vector<char>(3, '.')); 
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

    bool check_rows(char player){
        for (int i = 0; i < 3; i++){
            if (board->at(i).at(0) == player && board->at(i).at(1) == player && board->at(i).at(2) == player) {return true;}
        }
        return false;
    }
    bool check_cols(char player){
        for (int i = 0; i < 3; i++){
            if (board->at(0).at(i) == player && board->at(1).at(i) == player && board->at(2).at(i) == player) {return true;}
        }
        return false;
    }
    bool check_diags(char player){
        if (board->at(0).at(0) == player && board->at(1).at(1) == player && board->at(2).at(2) == player) {return true;}
        if (board->at(0).at(2) == player && board->at(1).at(1) == player && board->at(0).at(2) == player) {return true;}
        return false;
    }
    bool victory_check(char player){
        if (check_rows(player) || check_cols(player) || check_diags(player)){return true;}
        return false;
    }
    bool is_valid_space(int row, int col){
        if ((row > 2 || col > 2) || (row < 0 || col < 0)){return false;}
        if (board->at(row).at(col) == '#'){return true;}
        return false;
    }
    //Board representation method.
    void draw_board(){
        for (int i = 0; i < 3; i++){
            printf("|");
            for (int j = 0; j < 3; j++){
                printf("%c|",board->at(i).at(j));
            }
            printf("\n+-+-+-+\n");
        }
    }

    //getters and setters

    vector<vector<char>> * get_board(){return board;}
    void set_board(vector<vector<char>> * new_board){board = new_board;}
    char get_at_position(int i, int j){return board->at(i).at(j);}
    void set_at_position(int i, int j, char mark){board->at(i).at(j) = mark;}
};

class player
{
    private:
    game_board * board;
    vector<vector<int>> * curr_positions;

    public:
    player(game_board * game){
        board = game;
    }
    ~player();

    void move_to(int row, int col){
        board->set_at_position(row,col,'O');
        curr_positions->push_back({row,col});
    }
};

class ai_player
{
    private:
    game_board * board;
    vector<vector<int>> * curr_positions = new vector<vector<int>>(10, vector<int>(2));

    public:
    ai_player(game_board * game){
        board = game;
    }
    ~ai_player();

    //ai marks a spot on the gameboard as an 'X'.
    void move_to(int row, int col){
        board->set_at_position(row,col,'X');
        curr_positions->push_back({row,col});
    }
    //ai considers its options. 
    //The ai will consider the options it has for its next move compared to the player's.
    //The ai will determine the next spaces it could move to as well as the next spaces the player could move to.
    //The ai will pick one of the spaces that both the player and itself could move to.
    vector<vector<int>> * get_empty_neighbors(vector<int> * position)
    {
        vector<vector<int>> * neighbors = new vector<vector<int>>(10, vector<int>(2));
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if ((i == position->at(0)-1 || i == position->at(0)+1) && board->get_at_position(i,j) == '#'){neighbors->push_back({i,j});}
                if ((j == position->at(1)-1 || j == position->at(1)+1) && board->get_at_position(i,j) == '#'){neighbors->push_back({i,j});}
            }
        }
        return neighbors;
    }
    vector<vector<int>> determine_candidates(){
        vector<vector<int>> * possible_moves = new vector<vector<int>>(10, vector<int>(2)); 
        for (int i = 0; i < curr_positions->size(); i++){
            vector<vector<int>> temp = *get_empty_neighbors(&curr_positions->at(i));
            for (int j = 0; j < temp.size(); j++){possible_moves->push_back(temp.at(j));}
        }
        vector<vector<int>> * candidates = new vector<vector<int>>(10, vector<int>(2));
        bool has_dup = false;
        //find all duplicate moves.
        for (int i = 0; i < possible_moves->size(); i++){
            has_dup = false;
            for (int j = 0; j < possible_moves->size(); j++){
                if (possible_moves->at(i).at(0) == possible_moves->at(j).at(0) && possible_moves->at(i).at(0) == possible_moves->at(j).at(0)){
                    if (!has_dup){
                        has_dup = !has_dup;
                        candidates->push_back(possible_moves->at(i));
                    }
                }
            }
        }
        if (candidates->empty()){candidates = possible_moves;}
        return *candidates;
    }
    //ai considers its options. 
    //The ai will consider the options it has for its next move compared to the player's.
    //The ai will determine the next spaces it could move to as well as the next spaces the player could move to.
    //The ai will pick one of the spaces that both the player and itself could move to.
    void think_and_act(bool first_move){
        int x;
        int y;
        if (first_move){
            srand(time(0));
            x = rand()%3;
            y = rand()%3;
        }
        else{
            vector<vector<int>> * best_options = new vector<vector<int>>(10, vector<int>(2));
            *best_options = determine_candidates();
            bool thinking = true;
            int decided_move;
            while (thinking)
            {
              decided_move = rand()%best_options->size();
              if (find(curr_positions->begin(), curr_positions->end(), best_options->at(decided_move)) == curr_positions->end()){thinking = false;}   
            }
            x = best_options->at(decided_move).at(0);
            y = best_options->at(decided_move).at(1);
        }
        curr_positions->push_back({x,y});
        move_to(x,y);
    }
    
};

//main function for testing the basic game functions.
int main(){
    printf("Hello, world!\nTesting board inititialization...\n");
    game_board* board = new game_board();
    board->draw_board();
    printf("Testing ai_player inititialization...\n");
    ai_player* albert = new ai_player(board);
    printf("Testing player inititialization...\n");
    player* myself = new player(board);
    printf("Testing ai_player methods...\n");
    printf("...\n");
    albert->think_and_act(true);
    board->draw_board();
    printf("...\n");
    albert->think_and_act(false);
    board->draw_board();
    printf("...\n");
    albert->think_and_act(false);
    board->draw_board();




    
    return 0;
};
