#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

#define N 8  

typedef struct { int x, y; } Pos;  

Pos to_xy(const char* sq) { Pos p; p.x = sq[0] - 'a'; p.y = sq[1] - '1'; return p; }  
void xy_to_str(int x, int y, char out[3]) { out[0] = 'a' + x; out[1] = '1' + y; out[2] = '\0'; }  

int in_bounds(int x, int y) { return x>=0 && x<N && y>=0 && y<N; }  

// Path simples (exclui origem)  
typedef struct { char squares[64][3]; int cnt; } Path;  
void path_init(Path* p){ p->cnt=0; }  
void path_add(Path* p, const char s[3]) { strcpy(p->squares[p->cnt++], s); }  

// Torre (reta) - recursivo: avança em direção ao destino um passo por chamada até atingir  
Path path_rook_rec(const char* from, const char* to) {  
    Path p; path_init(&p);  
    Pos f = to_xy(from), t = to_xy(to);  
    if (f.x == t.x && f.y == t.y) return p;  
    // movimento recursivo simples: moveStep uma unidade em direção ao destino  
    int dx = (t.x > f.x) ? 1 : (t.x < f.x) ? -1 : 0;  
    int dy = (t.y > f.y) ? 1 : (t.y < f.y) ? -1 : 0;  
    if (dx != 0 && f.x != t.x) {  
        char next[3]; int nx = f.x + dx; int ny = f.y;  
        xy_to_str(nx, ny, next);  
        path_add(&p, next);  
        Path rest = path_rook_rec(next, to);  
        // append rest  
        for (int i=0;i<rest.cnt;i++) path_add(&p, rest.squares[i]);  
    } else if (dy != 0 && f.y != t.y) {  
        char next[3]; int nx = f.x; int ny = f.y + dy;  
        xy_to_str