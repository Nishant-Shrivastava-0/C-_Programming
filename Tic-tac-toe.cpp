#include <iostream>

using namespace std;

char board[3][3];
char currentPlayer = 'X'; 


void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + i * 3 + j; 
        }
    }
}


void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}


bool checkWin() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;

    return false;
}


bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}


void playGame() {
    int position;
    bool gameWon = false, gameDraw = false;

    initializeBoard(); 
    displayBoard();

    while (!gameWon && !gameDraw) {
        cout << "Player " << currentPlayer << ", enter the position (1-9) to mark: ";
        cin >> position;

        if (position < 1 || position > 9 || !makeMove(position)) {
            cout << "Invalid move! Try again." << endl;
        } else {
            displayBoard();
            gameWon = checkWin();
            gameDraw = checkDraw();

            if (!gameWon && !gameDraw) {
                switchPlayer();
            }
        }
    }

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else if (gameDraw) {
        cout << "It's a draw!" << endl;
    }
}


bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    do {
        playGame();
    } while (playAgain());

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}
