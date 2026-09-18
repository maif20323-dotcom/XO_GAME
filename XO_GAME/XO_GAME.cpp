
/*
 * ============================================================================
 * Project Name  : XO Game (Tic-Tac-Toe)
 * Description   : A 2-player console application built in C++ using Object-Oriented
 *                 Programming (OOP) principles, 2D arrays, and dynamic state validation.
 * Developer     : Eng. Mai Farag
 * Architecture  : Custom OOP Class-Based Design
 * Language      : C++
 * ============================================================================
 */

#include <iostream>
using namespace std;

class XOGame {
private:
    char board[3][3];      
    char currentPlayer;    
    int movesCount;       

public:
   
    XOGame() {
        resetGame();
    }

   
    void resetGame() {
        char cell = '1';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = cell++;
            }
        }
        currentPlayer = 'X'; 
        movesCount = 0;
    }

   
    void displayBoard() const {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << "\n";
    }

   
    bool makeMove(int choice) {
      
        if (choice < 1 || choice > 9) {
            cout << "Invalid??, input!Please choose a number from 1 to 9.  \n";
            return false;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

       
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "This slot is already booked?!Please choose another one:\n";
            return false;
        }

    
        board[row][col] = currentPlayer;
        movesCount++;
        return true;
    }

    bool checkWin() const {
        
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; 
        }
       
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; 
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    
    bool isDraw() const {
        return movesCount == 9 && !checkWin();
    }


    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

   
    void play() {
        cout << "===== Game XO (Tic-Tac-Toe) =====\n";

        while (true) {
            displayBoard();
            int move;
            cout <<"The Player " << currentPlayer << " Enter the number in box (1_9): ";


            if (!(cin >> move)) {
                cout << "Invalid input?!, Please enter a valid number \n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }


            if (!makeMove(move)) {
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Congratulations ! The winner is the player (" << currentPlayer << ")<<\n";
                break;
            }


            if (isDraw()) {
                displayBoard();
                cout << "The game ended in a draw!\n";
                break;
            }
        
         
            switchPlayer();
        }
    }
};

int main() {
    XOGame game;
    game.play(); 
    return 0;
}