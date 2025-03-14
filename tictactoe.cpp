#include <bits/stdc++.h>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        ResetBoard();
    }

    void ResetBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '1' + (i * 3 + j); 
            }
        }
        currentPlayer = 'X';
    }

    void PrintBoard() {
        system("cls"); 
        cout << "Tic-Tac-Toe Game\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << "\nCurrent Player: " << currentPlayer << "\n";
    }

    bool MakeMove(int move) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool CheckWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
        return false;
    }

    bool IsDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
            }
        }
        return true;
    }

    void SwitchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void Run() {
        int move;
        while (true) {
            PrintBoard();
            cout << "Enter your move (1-9): ";
            cin >> move;
            if (move < 1 || move > 9 || !MakeMove(move)) continue;

            if (CheckWin()) {
                PrintBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (IsDraw()) {
                PrintBoard();
                cout << "It's a draw!\n";
                break;
            }
            SwitchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.Run();
    return 0;
}
