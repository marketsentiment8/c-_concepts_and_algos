#include <iostream>
using namespace std;

void printBoard(char board[]) {
    for (int i = 0; i < 9; i++) {
        cout << board[i] << " ";
        if (i % 3 == 2) cout << endl;
    }
}

bool checkWin(char board[], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i*3] == player && board[i*3+1] == player && board[i*3+2] == player)
            return true;
        if (board[i] == player && board[i+3] == player && board[i+6] == player)
            return true;
    }
    if (board[0] == player && board[4] == player && board[8] == player)
        return true;
    if (board[2] == player && board[4] == player && board[6] == player)
        return true;
    return false;
}

bool checkDraw(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    }
    return true;
}

int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    char player = 'X';
    int move;

    while (true) {
        printBoard(board);
        cout << "Player " << player << ", enter your move: ";
        cin >> move;
        if (move < 1 || move > 9 || board[move-1] == 'X' || board[move-1] == 'O') {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        board[move-1] = player;
        if (checkWin(board, player)) {
            printBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            printBoard(board);
            cout << "The game is a draw!" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
