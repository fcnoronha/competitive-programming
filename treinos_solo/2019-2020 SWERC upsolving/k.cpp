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

#define maxn 112345

vi adj[maxn];
bool vis[maxn];
int deg[maxn];
int n, m, t;

vi path;

void dfs(int u) {

    if (vis[u]) return;
    vis[u] = 1;
    path.pb(u);

    if (deg[u] >= 2) return;
    deg[u]++;

    for (auto v: adj[u]) dfs(v);
}

int main() {
    fastio;

    cin >> n >> m >> t;

    vi especial;
    fr(i, m) {

        int u, v;
        cin >> u >> v;

        if (v == t) especial.pb(u);
        if (v == t || t == u) continue;

        adj[v].pb(u);
    }

    for (auto u: especial) {
        dfs(u);
        for (auto x: path) vis[x] = 0;
        path.clear();
    }

    vi ans;
    for (auto u: especial) if (deg[u] == 1) ans.pb(u);
        
    sort(all(ans));
    p(ans.size());
    for (auto u: ans) p(u);
}