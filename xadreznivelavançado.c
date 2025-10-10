#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 8

typedef struct {
    int x, y;
} Pos;


int in_bounds(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }


Pos algebraic_to_xy(const char* square) {
    Pos p;
    char file = square[0];
    char rank = square[1];
    p.x = file - 'a';
    p.y = rank - '1';
    return p;
}


void xy_to_algebraic(int x, int y, char out[3]) {
    out[0] = 'a' + x;
    out[1] = '1' + y;
    out[2] = '\0';
}


typedef struct {
    char grid[N][N]; 
} Board;

void board_init(Board* b) {
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) b->grid[i][j] = 0;
}

void board_place(Board* b, const char* pos, char piece) {
    Pos p = algebraic_to_xy(pos);
    b->grid[p.x][p.y] = piece;
}

char board_at(Board* b, int x, int y) {
    if (!in_bounds(x,y)) return 0;
    return b->grid[x][y];
}


typedef struct {
    char squares[64][3];
    int count;
} Path;

void path_init(Path* p) { p->count = 0; }

void path_add(Path* p, const char* sq) {
    strcpy(p->squares[p->count], sq);
    p->count++;
}


Path path_rook(const char* from_pos, const char* to_pos) {
    Path path; path_init(&path);
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    if (f.x == t.x && f.y == t.y) return path;
    if (f.x == t.x) {
        int step = (t.y > f.y) ? 1 : -1;
        for (int y = f.y + step; y != t.y + step; y += step) {
            char sq[3];
            xy_to_algebraic(f.x, y, sq);
            path_add(&path, sq);
        }
    } else if (f.y == t.y) {
        int step = (t.x > f.x) ? 1 : -1;
        for (int x = f.x + step; x != t.x + step; x += step) {
            char sq[3];
            xy_to_algebraic(x, f.y, sq);
            path_add(&path, sq);
        }
    }
    return path;
}


Path path_bishop(const char* from_pos, const char* to_pos) {
    Path path; path_init(&path);
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    int dx = (t.x > f.x) ? 1 : -1;
    int dy = (t.y > f.y) ? 1 : -1;
    int x = f.x + dx;
    int y = f.y + dy;
    while (x != t.x || y != t.y) {
        char sq[3];
        xy_to_algebraic(x, y, sq);
        path_add(&path, sq);
        x += dx; y += dy;
    }
    return path;
}


Path path_queen(const char* from_pos, const char* to_pos) {
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    if (f.x == t.x || f.y == t.y) return path_rook(from_pos, to_pos);
    else return path_bishop(from_pos, to_pos);
}


Path path_knight(const char* from_pos, const char* to_pos) {
    Path path; path_init(&path);
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    int dx = (t.x - f.x); if (dx<0) dx = -dx;
    int dy = (t.y - f.y); if (dy<0) dy = -dy;
    if (!((dx==1 && dy==2) || (dx==2 && dy==1))) return path;
    path_add(&path, to_pos);
    return path;
}


bool valid_rook_move(const char* from_pos, const char* to_pos, Board* b) {
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    if (f.x != t.x && f.y != t.y) return false;
    Path p = path_rook(from_pos, to_pos);
    for (int i=0; i<p.count; i++) {
        char sq[3];
        strcpy(sq, p.squares[i]);
        Pos pp = algebraic_to_xy(sq);
        if (board_at(b, pp.x, pp.y) != 0) return false;
    }
    return true;
}
bool valid_bishop_move(const char* from_pos, const char* to_pos, Board* b) {
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    if (abs(t.x - f.x) != abs(t.y - f.y)) return false;
    Path p = path_bishop(from_pos, to_pos);
    for (int i=0; i<p.count; i++) {
        char sq[3];
        strcpy(sq, p.squares[i]);
        Pos pp = algebraic_to_xy(sq);
        if (board_at(b, pp.x, pp.y) != 0) return false;
    }
    return true;
}
bool valid_queen_move(const char* from_pos, const char* to_pos, Board* b) {
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    bool straight = (f.x == t.x || f.y == t.y);
    bool diag = (abs(t.x - f.x) == abs(t.y - f.y));
    if (!(straight || diag)) return false;
    Path p = path_queen(from_pos, to_pos);
    for (int i=0; i<p.count; i++) {
        char sq[3];
        strcpy(sq, p.squares[i]);
        Pos pp = algebraic_to_xy(sq);
        if (board_at(b, pp.x, pp.y) != 0) return false;
    }
    return true;
}
bool valid_knight_move(const char* from_pos, const char* to_pos) {
    Pos f = algebraic_to_xy(from_pos);
    Pos t = algebraic_to_xy(to_pos);
    int dx = abs(t.x - f.x);
    int dy = abs(t.y - f.y);
    return (dx==1 && dy==2) || (dx==2 && dy==1);
}


void print_directions_between(const char* from_pos, const Path* path) {
    
    char current[3];
    strcpy(current, from_pos);
    for (int i = 0; i < path->count; i++) {
        const char* next = path->squares[i];
        Pos c = algebraic_to_xy(current);
        Pos n = algebraic_to_xy(next);
        int dx = n.x - c.x;
        int dy = n.y - c.y;
        if (dx == 0 && dy == 1) printf("Cima\n");
        else if (dx == 0 && dy == -1) printf("Baixo\n");
        else if (dx == 1 && dy == 0) printf("Direita\n");
        else if (dx == -1 && dy == 0) printf("Esquerda\n");
        else if (dx == 1 && dy == 1) printf("Cima-Dir\n"); // opcional
        else if (dx == -1 && dy == 1) printf("Cima-Esq\n");
        else if (dx == 1 && dy == -1) printf("Baixo-Dir\n");
        else if (dx == -1 && dy == -1) printf("Baixo-Esq\n");
        else printf("Movimento desconhecido\n");
        strcpy(current, next);
    }
}

int main(void) {
    Board b;
    board_init(&b);

   
    board_place(&b, "a1", 'R');
    board_place(&b, "c1", 'N');
    board_place(&b, "f1", 'B');
    board_place(&b, "d1", 'Q');

    
    const char* from_rook = "a1";
    const char* to_rook = "a4";
    if (valid_rook_move(from_rook, to_rook, &b)) {
        Path p = path_rook(from_rook, to_rook);
        print_directions_between(from_rook, &p);
    } else {
        printf("Movimento invalido para Torre\n");
    }
    printf("\n"); 

   
    const char* from_bishop = "f1";
    const char* to_bishop = "c4";
    if (valid_bishop_move(from_bishop, to_bishop, &b)) {
        Path p = path_bishop(from_bishop, to_bishop);
        print_directions_between(from_bishop, &p);
    } else {
        printf("Movimento invalido para Bispo\n");
    }
    printf("\n");

   
    const char* to_queen = "h5";
    if (valid_queen_move(from_queen, to_queen, &b)) {
        Path p = path_queen(from_queen, to_queen);
        print_directions_between(from_queen, &p);
    } else {
        printf("Movimento invalido para Rainha\n");
    }
    printf("\n");


    const char* from_knight = "c1";
    const char* to_knight = "d3";
    if (valid_knight_move(from_knight, to_knight)) {
        Path p = path_knight(from_knight, to_knight);
        print_directions_between(from_knight, &p);
    } else {
        printf("Movimento invalido para Cavalo\n");
    }
    printf("\n");

    return 0;
}