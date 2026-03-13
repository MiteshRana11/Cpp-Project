#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {

private:
    vector<vector<char>> board;

public:

    TicTacToe() {
        board = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
        };
    }

    void display() {

        cout << endl;

        for(auto &row : board){

            for(char cell : row)
                cout << cell << " ";

            cout << endl;
        }

        cout << endl;
    }

    void play() {

        char player = 'X';
        int move;

        for(int i=0;i<9;i++){

            display();

            cout << "Player " << player << " move: ";
            cin >> move;

            int r = (move-1)/3;
            int c = (move-1)%3;

            if(board[r][c]=='X' || board[r][c]=='O'){
                cout << "Invalid move\n";
                i--;
                continue;
            }

            board[r][c] = player;

            player = (player=='X') ? 'O' : 'X';
        }

        display();
        cout << "Game Over\n";
    }
};

int main(){

    TicTacToe game;
    game.play();

}