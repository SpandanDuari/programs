#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int isDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0;
    return 1;
}

void computerMove() {
    int choice, row, col;
    do {
        choice = (rand() % 9) + 1;
        row = (choice - 1) / SIZE;
        col = (choice - 1) % SIZE;
    } while (board[row][col] == 'X' || board[row][col] == 'O');
    
    printf("Computer chooses position %d\n", choice);
    board[row][col] = 'O';
}

void playGame() {
    int player = 1, choice;
    char mark;
    srand(time(0));

    while (1) {
        printBoard();
        if (player == 1) {
            mark = 'X';
            printf("Player, enter position (1-9): ");
            scanf("%d", &choice);

            int row = (choice - 1) / SIZE;
            int col = (choice - 1) % SIZE;

            if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
                printf("Invalid move, try again.\n");
                continue;
            }
            board[row][col] = mark;
        } else {
            computerMove();
        }

        if (checkWin()) {
            printBoard();
            if (player == 1) {
                printf("Player wins!\n");
            } else {
                printf("Computer wins!\n");
            }
            break;
        }

        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }
}

int main() {
    printf("Welcome to Tic Tac Toe! You are Player 1 (X). Computer is Player 2 (O).\n");
    playGame();
    return 0;
}
