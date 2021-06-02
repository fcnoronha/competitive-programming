#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

#define maxn 112345

vi adj[maxn];
ll val[maxn][2], memo[maxn][2];

ll pd(int u, int j, int prt = -1) {

    ll &pdm = memo[u][j];
    if (pdm != -1) return pdm;

    pdm = 0;
    for (auto v: adj[u]) {
        if (v == prt) continue;
        ll vl = abs(val[u][j] - val[v][0]) + pd(v, 0, u);
        ll vr = abs(val[u][j] - val[v][1]) + pd(v, 1, u);
        pdm += max(vl, vr);
    }

    return pdm;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;

        fr(i, n) {
            adj[i].clear();
            memo[i][0] = memo[i][1] = -1;
            fr(j, 2) cin >> val[i][j];
        }

        fr(i, n-1) {
            int u, v; cin >> u >> v;
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

    cout << max(pd(0, 0), pd(0, 1)) << endl;
    }
}
