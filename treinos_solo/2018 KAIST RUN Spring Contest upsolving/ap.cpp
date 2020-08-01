//codeforces.com/gym/101806/problem/P

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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    int r, c, k;
    cin >> r >> c >> k;

    int grid[r][c];
    for (int i = r-1; i >= 0; i--)
        fr(j, c) 
            cin >> grid[i][j];

    int h[c];
    fr(j, c) {
        h[j] = 0;
        fr(i, r) h[j] += (grid[i][j] != 0);
    }

    vector< vector<int> > ans;
    fr(j, c) {
        if (h[j]%2 == 0) continue;

        int col_in = grid[0][j], col_out = col_in+1;
        if (col_out > k) col_out = 1; 

        vector<int> aux(4);
        aux = {1, j+1, col_out, col_in};
        ans.pb(aux);

        aux = {1, j+1, col_out, col_out};
        ans.pb(aux);

        aux = {1, j+1, col_out, col_out};
        ans.pb(aux);
    }

    fr(j, c) {
        if (h[j] <= 1) continue;

        int i = h[j]%2;
        while (i < r && grid[i][j]) {
            vector<int> aux(4);
            aux = {1, j+1, grid[i+1][j], grid[i][j]};
            ans.pb(aux);
            i += 2;
        }
    }

    p(ans.size());
    for (auto v: ans) pv(v);
}
