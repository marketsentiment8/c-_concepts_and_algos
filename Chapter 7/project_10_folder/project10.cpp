#include <iostream>
#include <vector>

// Function to print the tic-tac-toe board
void printBoard(const std::vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        std::cout << board[i] << " ";
        if ((i + 1) % 3 == 0)
            std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    return ((board[0] == player && board[1] == player && board[2] == player) ||
            (board[3] == player && board[4] == player && board[5] == player) ||
            (board[6] == player && board[7] == player && board[8] == player) ||
            (board[0] == player && board[3] == player && board[6] == player) ||
            (board[1] == player && board[4] == player && board[7] == player) ||
            (board[2] == player && board[5] == player && board[8] == player) ||
            (board[0] == player && board[4] == player && board[8] == player) ||
            (board[2] == player && board[4] == player && board[6] == player));
}

int main() {
    std::vector<char> board(9, ' '); // Initialize an empty board
    char currentPlayer = 'X'; // Player X starts
    int position;

    std::cout << "Let's play Tic-Tac-Toe!\n";
    std::cout << "Player X starts. Enter position (1-9):" << std::endl;

    while (true) {
        printBoard(board);
        std::cin >> position;

        if (position < 1 || position > 9 || board[position - 1] != ' ') {
            std::cout << "Invalid move. Please try again." << std::endl;
            continue;
        }

        board[position - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }

        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';

        if (std::count(board.begin(), board.end(), ' ') == 0) {
            printBoard(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        std::cout << "Player " << currentPlayer << "'s turn. Enter position (1-9):" << std::endl;
    }

    return 0;
}
