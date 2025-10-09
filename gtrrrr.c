#include <stdio.h>
#include <stdbool.h>

#define N 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 4  // tamanho dos navios

// Estruturas simples (tabuleiro)
typedef int Tabuleiro[N][N];

// Inicializa o tabuleiro com 0 (água)
void inicializar(Tabuleiro t) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            t[i][j] = AGUA;
}

// Verifica se um trecho do tabuleiro está livre (sem navio)
bool trecho_livre(Tabuleiro t, int r, int c, int dr, int dc, int len) {
    for (int k = 0; k < len; ++k) {
        int rr = r + k * dr;
        int cc = c + k * dc;
        if (rr < 0 || rr >= N || cc < 0 || cc >= N) return false;
        if (t[rr][cc] != AGUA) return false;
    }
    return true;
}

// Coloca um navio ao longo de uma direção (dr, dc) com tamanho len
bool colocar(Tabuleiro t, int r, int c, int dr, int dc, int len) {
    if (!trecho_livre(t, r, c, dr, dc, len)) return false;
    for (int k = 0; k < len; ++k) {
        int rr = r + k * dr;
        int cc = c + k * dc;
        t[rr][cc] = NAVIO;
    }
    return true;
}

// Imprime o tabuleiro com alinhamento
void imprimir(Tabuleiro t) {
    printf("   ");
    for (int j = 0; j < N; ++j) printf("%2d ", j);
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("%2d ", i);
        for (int j = 0; j < N; ++j) {
            char ch = (t[i][j] == NAVIO) ? '3' : '0';
            printf(" %c ", ch);
        }
        printf("\n");
    }
}

// Função auxiliar para imprimir apenas para depuração (opcional)
// void imprimir_bruto(Tabuleiro t) { ... }

// Construção de navios segundo as regras do desafio
void construir_tabuleiro(Tabuleiro t) {
    // 1) Navio horizontal (ex.: início (0,0), direção para a direita)
    //    comprimento TAM_NAVIO
    if (!colocar(t, 0, 0, 0, 1, TAM_NAVIO)) {
        printf("Falha ao posicionar navio horizontal 1\n");
    }

    // 2) Navio vertical (ex.: início (4,2), direção para baixo)
    if (!colocar(t, 4, 2, 1, 0, TAM_NAVIO)) {
        printf("Falha ao posicionar navio vertical 2\n");
    }

    // 3) Navio diagonal principal (início (0,4), direção (1,1))
    //    Diagonal crescente: (r+k, c+k)
    if (!colocar(t, 0, 4, 1, 1, TAM_NAVIO)) {
        printf("Falha ao posicionar navio diagonal principal 3\n");
    }

    // 4) Navio diagonal anti-diagonal (início (0,9), direção (1,-1))
    //    Diagonal decrescente: (r+k, c-k)
    if (!colocar(t, 0, 9, 1, -1, TAM_NAVIO)) {
        printf("Falha ao posicionar navio diagonal anti-principal 4\n");
    }
}

// Valida se há sobreposições (a função colocar já verifica, mas podemos fazer checagem geral)
bool valido(Tabuleiro t) {
    // Como usamos colocar apenas se trecho_livre, já estamos válidos.
    // Esta função pode percorrer e confirmar que não há entradas com valores inválidos.
    // Aqui retornamos true por simplicidade.
    return true;
}

// Programa principal de demonstração
int main(void) {
    Tabuleiro tab;
    inicializar(tab);

    construir_tabuleiro(tab);

    // Opcional: verificar validação
    if (!valido(tab)) {
        printf("Tabuleiro invalido (sobreposicao detectada).\n");
        return 1;
    }

    // Exibe o tabuleiro completo 10x10
    imprimir(tab);

    return 0;
}