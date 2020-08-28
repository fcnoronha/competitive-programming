#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

typedef vector< vector<ui> > matrix;

// defining function to multiplicate a matrix
matrix operator*(matrix &a, matrix &b) {
    int ai = a.size(); 
    int aj = a[0].size();
    int bj = b[0].size();
    matrix aux(ai, vector<ui>(bj, 0));
    for (int k = 0; k < aj; k++)
        for (int i = 0; i < ai; i++) 
            for (int j = 0; j < bj; j++)
                aux[i][j] = (aux[i][j] + (a[i][k]*b[k][j]));
    return aux;
}

// idendity matrix
matrix id(int x) {
    matrix v(x, vector<ui>(x, 0));
    for (int i = 0; i < x; i++) v[i][i] = 1;
    return v;
}

// exponentiate a matrix 'a' by a factor 'x'
void exp(matrix &a, int x) {
    matrix ans = id(a.size());
    while (x) {
        if (x%2) ans = ans*a;
        a = a*a;
        x /= 2;
    }
    a = ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int k;
    cin >> k;

    matrix v(65, vector<ui>(65, 0));
    fr(i, 8) fr(j, 8) {
        for (int ii: {-2, -1, 1, 2}) 
            for (int jj: {-2, -1, 1, 2}) {
                if (abs(ii) == abs(jj)) continue;
                int ni = i+ii;
                int nj = j+jj;
                if (ni < 0 || ni >= 8) continue;
                if (nj < 0 || nj >= 8) continue;
                v[i*8 + j][ni*8 + nj] = 1;
            }
    }
    fr(i, 65) v[i][64] = 1;

    exp(v, k+1);
    p(v[0][64]);
}
