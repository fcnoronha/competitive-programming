//codeforces.com/contest/994/problem/C

#include "bits/stdc++.h"
using namespace std;

// definindo um ponto
typedef pair<int, int> point;
#define x first
#define y second

// definindo um poligono
typedef vector<pair<int, int>> polygon;

// testa se o ponto c esta a esquerda da reta a->b
int is_left(point a, point b, point c) {
    int det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // c esta a esquerda
    if (det < 0) return -1; // c esta a direita
    return 0;               // c é colinear
}

// checa se o ponto q esta dentro do poligono p
bool is_inside(polygon p, point q) {
    int n = p.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[is_left(p[i], p[(i+1)%n], q)]++;
    return (mp[1] == 0 || mp[-1] == 0); 
}

int main() {
  
}