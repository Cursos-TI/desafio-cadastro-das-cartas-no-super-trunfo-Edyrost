#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10  // tamanho do tabuleiro (10x10)

typedef enum {
    C_VAZIO,     // célula vazia
    C_NAVIO,      // parte de navio
    C_SHOT        // já atingida (ou marca de tiro)
} Celula;

typedef struct {
    Celula g[N][N];
} Tabuleiro;

// Inicializa o tabuleiro com células vazias
void inicializar(Tabuleiro *t) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            t->g[i][j] = C_VAZIO;
}

// Impõe navios apenas em posições diagonais
// Ex.: coloca um navio de tamanho len na diagonal principal a partir de (r,c)
// O navio ocupa (r,c), (r+1,c+1), (r+2,c+2), ... até len células
bool colocar_diagonal(Tabuleiro *t, int r, int c, int len) {
    if (r < 0 || c < 0 || r + len > N || c + len > N)
        return false; // fora do tabuleiro

    // Verificar se há espaço livre ao longo da diagonal
    for (int k = 0; k < len; ++k) {
        int rr = r + k;
        int cc = c + k;
        if (t->g[rr][cc] != C_VAZIO)
            return false;
    }

    // Colocar o navio ao longo da diagonal
    for (int k = 0; k < len; ++k) {
        t->g[r + k][c + k] = C_NAVIO;
    }
    return true;
}

// Imprimir o tabuleiro (para debug)
void imprimir(const Tabuleiro *t) {
    printf("   ");
    for (int j = 0; j < N; ++j) printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < N; ++i) {
        printf("%2d ", i);
        for (int j = 0; j < N; ++j) {
            char ch;
            switch (t->g[i][j]) {
                case C_VAZIO: ch = '.'; break;
                case C_NAVIO:  ch = 'N'; break;
                case C_SHOT:   ch = '*'; break;
                default: ch = '?';
            }
            printf(" %c ", ch);
        }
        printf("\n");
    }
}

// Atira na posição (r, c)
bool atirar(Tabuleiro *t, int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= N) return false;
    if (t->g[r][c] == C_NAVIO) {
        t->g[r][c] = C_SHOT;
        return true; // acertou
    } else {
        t->g[r][c] = C_SHOT;
        return false; // erro
    }
}

// Exemplo de construção de tabuleiro com navios diagonais completos
// Esta função posiciona alguns navios diagonais de tamanhos variados
void construir_diagonais_exemplo(Tabuleiro *t) {
    // Coordenas iniciais e comprimentos (exemplos)
    colocar_diagonal(t, 0, 0, 4); // navio diagonal de tamanho 4 na diagonal (0,0)-(3,3)
    colocar_diagonal(t, 1, 4, 3); // (1,4)-(3,6)
    colocar_diagonal(t, 5, 1, 2); // (5,1)-(6,2)
    colocar_diagonal(t, 7, 7, 3); // (7,7)-(9,9)
}

// Menu simples de demonstração
int main(void) {
    Tabuleiro t;
    inicializar(&t);

    construir_diagonais_exemplo(&t);
    imprimir(&t);

    // Exemplo de tiro
    int r, c;
    printf("Tiro em (2,2): ");
    if (scanf("%d %d", &r, &c) == 2) {
        bool acerto = atirar(&t, r, c);
        printf("Resultado: %s\n", acerto ? "acerto" : "agua");
        imprimir(&t);
    }

    return 0;
}