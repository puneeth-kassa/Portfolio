 #include <stdio.h>
 // Structure to represent the Tic-Tac-Toe game
 struct TicTacToe {
    char board[3][3];
    char currentPlayer;
 };
 // Function to print the Tic-Tac-Toe board
 void printBoard(struct TicTacToe* game) {
    printf("    1   2    3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
 }
 // Function to check if a player has won
 int checkWin(struct TicTacToe* game) {
    char player = game->currentPlayer;
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
if ((game->board[i][0] == player && game->board[i][1] == 
player && game->board[i][2] == player) ||
 (game->board[0][i] == player && game->board[1][i] == 
player && game->board[2][i] == player)) {
            return 1; // Player wins
        }
    }
    // Check diagonals
 if ((game->board[0][0] == player && game->board[1][1] == 
player && game->board[2][2] == player) ||
 (game->board[0][2] == player && game->board[1][1] == 
player && game->board[2][0] == player)) {
        return 1; // Player wins
    }
    return 0; // No winner yet
 }
 // Function to check if the board is full
 int isBoardFull(struct TicTacToe* game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->board[i][j] == ' ') {
                r
 eturn 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}
 // Function to make a move
 void makeMove(struct TicTacToe* game, int row, int col) {
    game->board[row - 1][col - 1] = game->currentPlayer;
 }
 int main() {
    struct TicTacToe game;
    game.currentPlayer = 'X';
  // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game.board[i][j] = ' ';
        }
    }
        printf("Welcome to Tic-Tac-Toe!\n");
    do {
        // Print the current board
        printBoard(&game);
        // Get player move
 printf("Player %c, enter your move (row and column): ", 
game.currentPlayer);
        int row, col;
        scanf("%d %d", &row, &col);
        // Check if the move is valid
if (row < 1 || row > 3 || col < 1 || col > 3 || game.board[row - 
1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        // Make the move
        makeMove(&game, row, col);
        // Check if the current player wins
        if (checkWin(&game)) {
            printBoard(&game);
            printf("Player %c wins!\n", game.currentPlayer);
            break;
        }
        // Check if the board is full (draw)
        if (isBoardFull(&game)) {
            printBoard(&game);
            printf("It's a draw!\n");
            break;
        }
       // Switch to the other player
    game.currentPlayer = (game.currentPlayer == 'X') ? 'O' : 'X';
   } while (1);
    return 0;
 }
