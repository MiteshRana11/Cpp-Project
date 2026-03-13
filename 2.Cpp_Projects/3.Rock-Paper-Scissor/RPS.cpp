#include <iostream>
#include <random>
#include <string>

using namespace std;

enum class Move { Rock = 1, Paper, Scissors };

class Game {
private:
    int playerScore = 0;
    int computerScore = 0;

    Move getComputerMove() {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dist(1,3);

        return static_cast<Move>(dist(gen));
    }

    string moveToString(Move move) {
        switch(move){
            case Move::Rock: return "Rock";
            case Move::Paper: return "Paper";
            case Move::Scissors: return "Scissors";
        }
        return "";
    }

    void evaluateRound(Move player, Move computer) {

        if(player == computer) {
            cout << "Draw!\n";
            return;
        }

        if((player == Move::Rock && computer == Move::Scissors) ||
           (player == Move::Paper && computer == Move::Rock) ||
           (player == Move::Scissors && computer == Move::Paper)) {

            playerScore++;
            cout << "You Win!\n";
        }
        else {
            computerScore++;
            cout << "Computer Wins!\n";
        }
    }

public:

    void start() {

        int choice;

        while(true){

            cout << "\n1.Rock 2.Paper 3.Scissors 4.Exit\n";
            cin >> choice;

            if(choice == 4) break;

            Move playerMove = static_cast<Move>(choice);
            Move computerMove = getComputerMove();

            cout << "Computer chose: " << moveToString(computerMove) << endl;

            evaluateRound(playerMove, computerMove);

            cout << "Score → You: " << playerScore
                 << " Computer: " << computerScore << endl;
        }
    }
};

int main() {

    Game game;
    game.start();

}