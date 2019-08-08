// https://www.urionlinejudge.com.br/judge/en/problems/view/2241

#include "bits/stdc++.h"
using namespace std;

int acb[505][505], acw[505][505], n, p, ansb, answ, i, j, k, x, y, b, w;

int main(){

    cin >> n >> p;

    for (i = 0; i < p; i++){
        cin >> x >> y;
        acb[x][y] = 1;
    }

    for (i = 0; i < p; i++){
        cin >> x >> y;
        acw[x][y] = 1;
    }

    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++){
        acb[i][j] += acb[i-1][j];
        acb[i][j] += acb[i][j-1];
        acb[i][j] -= acb[i-1][j-1];

        acw[i][j] += acw[i-1][j];
        acw[i][j] += acw[i][j-1];
        acw[i][j] -= acw[i-1][j-1];
    }

    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++){
        int mx = min(n-i, n-j);

        for (k = 0; k <= mx; k++){
            b = acb[i+k][j+k];
            b -= acb[i-1][j+k];
            b -= acb[i+k][j-1];
            b += acb[i-1][j-1];

            w = acw[i+k][j+k];
            w -= acw[i-1][j+k];
            w -= acw[i+k][j-1];
            w += acw[i-1][j-1];
            
            if (w == 0 && b > 0) ansb++;
            else if (b == 0 && w > 0) answ++;
        }     
    }

    cout << ansb << " " << answ << endl;
}
