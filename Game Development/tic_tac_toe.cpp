#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

void drawBoard() {
    cout << "Tic-Tac-Toe" << endl;
    cout << "-------------" << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "| " << board[row][col] << " ";
        }
        cout << "|\n";
        cout << "-------------" << endl;
    }
}

bool isMoveValid(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool isGameOver() {
    // Check for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Horizontal win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Vertical win
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Diagonal win (top-right to bottom-left)
    }

    // Check for a draw
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return false; // The game is not over if there is an empty space
            }
        }
    }
    // If no empty spaces are left and no player has won, it's a draw.
    return true;
}

int main() {
    int row, col;

    while (true) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter row and column (e.g., 1 2): ";
        cin >> row >> col;

        if (isMoveValid(row - 1, col - 1)) {
            board[row - 1][col - 1] = currentPlayer;
            if (isGameOver()) {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
