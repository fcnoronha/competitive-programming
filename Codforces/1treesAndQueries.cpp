//codeforces.com/contest/1304/problem/E

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

#define maxn 100009
#define maxl 20

int timer;
int tin[maxn], tout[maxn], up[maxn][maxl], lvl[maxn];
vi adj[maxn];

void dfs_lca(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i < maxl; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) 
        if (u != p) {
            lvl[u] = lvl[v] + 1; 
            dfs_lca(u, v);
        }
    
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = maxl-1; i >= 0; --i) 
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return lvl[u]+lvl[v]-lvl[l]-lvl[l];
}

int main() {

    int n;
    cin >> n;
    int u, v;
    fr(i, n-1) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs_lca(1, 1);
    int q;
    cin >> q;
    int x, y, a, b, k;
    while (q--) {
        cin >> x >> y >> a >> b >> k;
        int d1 = dist(a, b);
        int d2 = min(dist(a, x)+dist(y, b), dist(a,y)+dist(x,b)) + 1;

        if (k >= d1 && k%2 == d1%2) {
            p("YES");
            continue;
        }
        if (k >= d2 && k%2 == d2%2) {
            p("YES");
            continue;
        }

        p("NO");
    }
}
