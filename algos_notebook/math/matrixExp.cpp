
// MATRIX EXPONENTIATION

const ll mod = 1000000007; // To be defined
typedef vector< vector<ll> > matrix;

// defining function to multiplicate a matrix
matrix operator*(matrix &a, matrix &b) {
    int ai = a.size(); 
    int aj = a[0].size();
    int bj = b[0].size();
    matrix aux(ai, vector<ll>(bj, 0ll));
    for (int k = 0; k < aj; k++) 
        for (int i = 0; i < ai; i++) 
            for (int j = 0; j < bj; j++) {
                aux[i][j] += a[i][k]*b[k][j];
                if (aux[i][j] > 8ll*mod*mod) 
                    aux[i][j] -= 8ll*mod*mod;
            }
    for (int i = 0; i < ai; i++) 
        for (int j = 0; j < bj; j++)
            aux[i][j] %= mod;
    // erase part above if mod is bigger than 1e9 and 
    // take modulo the normal way
    return aux;
}

// idendity matrix
matrix id(int x) {
    matrix v(x, vector<ll>(x, 0));
    for (int i = 0; i < x; i++) v[i][i] = 1ll;
    return v;
}

// exponentiate a matrix 'a' by a factor 'x'
void exp(matrix &a, ll x) {
    matrix ans = id(a.size());
    while (x) {
        if (x%2) ans = ans*a;
        a = a*a;
        x /= 2;
    }
    a = ans;
}
