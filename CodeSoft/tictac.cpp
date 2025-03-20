#include <iostream>

using namespace std;

char board[3][3]; // 3x3 grid for the game
char currentPlayer = 'X'; // 'X' starts the game

// Function to initialize the board
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++; // Filling board with numbers 1-9
        }
    }
}

// Function to display the current board
void displayBoard() {
    cout << "\n Tic-Tac-Toe Game \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---\n";
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||  // Row check
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {  // Column check
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||  
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {  
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // If any cell is empty, game is not a draw
            }
        }
    }
    return true;
}

// Function to take input and update the board
void playerMove() {
    int choice;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;
        
        if (choice < 1 || choice > 9) {
            cout << "Invalid input! Choose a number between 1 and 9.\n";
            continue;
        }
        
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken! Choose another.\n";
        } else {
            board[row][col] = currentPlayer;
            break;
        }
    }
}

// Function to switch the current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to play the game
void playGame() {
    initializeBoard();
    currentPlayer = 'X';
    bool gameRunning = true;

    while (gameRunning) {
        displayBoard();
        playerMove();
        
        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (checkDraw()) {
            displayBoard();
            cout << "The game is a draw!\n";
            break;
        }
        switchPlayer();
    }
}

// Main function
int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}