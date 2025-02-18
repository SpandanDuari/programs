#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1; // Row check
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1; // Column check
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1; // Diagonal check
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int isDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0; // If any position is still a number, the game isn't drawn
    return 1;
}

void playGame() {
    int player = 1, choice;
    char mark;
    
    while (1) {
        printBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter position (1-9): ", player);
        scanf("%d", &choice);

        int row = (choice - 1) / SIZE;
        int col = (choice - 1) % SIZE;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[row][col] = mark;

        if (checkWin()) {
            printBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player++;
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    playGame();
    return 0;
}