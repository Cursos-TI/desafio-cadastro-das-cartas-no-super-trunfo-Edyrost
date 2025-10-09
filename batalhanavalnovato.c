#include <stdio.h>
#include <stdbool.h>

#define N 10  // tamanho do tabuleiro

// Inicializa o tabuleiro com água ('~')
void initBoard(char board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = '~';
        }
    }
}

// Imprime o tabuleiro
void printBoard(char board[N][N]) {
    printf("  ");
    for (int j = 0; j < N; ++j) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < N; ++i) {
        printf("%d ", i);
        for (int j = 0; j < N; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Verifica se é possível colocar um navio de tamanho 'size'
// na posição (row, col) com orientação horizontal ou vertical
bool canPlace(char board[N][N], int row, int col, int size, bool horizontal) {
    if (horizontal) {
        // checa se cabe na linha
        if (col + size > N) return false;
        for (int j = 0; j < size; ++j) {
            if (board[row][col + j] != '~') return false; // já usado
        }
    } else {
        // vertical
        if (row + size > N) return false;
        for (int i = 0; i < size; ++i) {
            if (board[row + i][col] != '~') return false;
        }
    }
    return true;
}

// Coloca o navio no tabuleiro
void placeShip(char board[N][N], int row, int col, int size, bool horizontal, char symbol) {
    if (!canPlace(board, row, col, size, horizontal)) {
        printf("Impossível posicionar o navio na posição dada.\n");
        return;
    }

    if (horizontal) {
        for (int j = 0; j < size; ++j) {
            board[row][col + j] = symbol;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            board[row + i][col] = symbol;
        }
    }
}

// Exemplo de uso
int main(void) {
    char board[N][N];
    initBoard(board);

    // Exemplo: posicionar alguns navios
    // Navio de tamanho 3 horizontal na linha 0, coluna 0
    placeShip(board, 0, 0, 3, true, 'A');
    // Navio de tamanho 3 vertical na linha 2, coluna 5
    placeShip(board, 2, 5, 3, false, 'B');
   
    
    printBoard(board);
    return 0;
}