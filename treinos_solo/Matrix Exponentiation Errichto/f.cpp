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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

typedef vector< vector<ll> > matrix;

// defining function to multiplicate a matrix
matrix operator*(matrix &a, matrix &b) {
    int ai = a.size(); 
    int aj = a[0].size();
    int bj = b[0].size();
    matrix aux(ai, vector<ll>(bj, 3e18+5));
    for (int k = 0; k < aj; k++)
        for (int i = 0; i < ai; i++) 
            for (int j = 0; j < bj; j++)
                aux[i][j] = min(aux[i][j], (a[i][k]+b[k][j]));
    return aux;
}

// idendity matrix
matrix id(int x) {
    matrix v(x, vector<ll>(x, 0));
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

    int n, m, k;
    cin >> n >> m >> k;

    matrix v(n, vector<ll>(n, 3e18L+5));
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a-1][b-1] = c;
    }

    exp(v, k);
    ll ans = 3e18L+5;
    fr(i, n) fr(j, n)
        ans = min(ans, v[i][j]);
    
    if (ans >= 1e18L + 5) {
        p("IMPOSSIBLE");
        return 0;
    }

    p(ans);
}
