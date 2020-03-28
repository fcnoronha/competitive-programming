//codeforces.com/contest/1294/problem/E

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    int grid[n][m];
    fr(i, n) fr(j, m) {
        cin >> grid[i][j];
        grid[i][j]--;
    }

    ll ans = 0ll;
    fr(col, m) {

        vi cnt(n, 0);
        int hasto = 0;
        int inpos = 0;
        fr(lin, n) {

            int a = grid[lin][col];
            if (a%m != col) {
                hasto++;
                continue;
            } 
            int right_lin = a/m;
            if (right_lin == lin) inpos++;
            if (right_lin >= n) continue;
            cnt[(lin-right_lin+n)%n]++;
        }

        if (inpos == n) continue;
        int best = n-inpos;
        fr(i, n) best = min(best, n-cnt[i]+i);
        ans += best;
    }

    p(ans);
}
