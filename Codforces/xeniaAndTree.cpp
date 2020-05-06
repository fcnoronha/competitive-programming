//codeforces.com/contest/342/problem/E

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
int mn[maxn];

// LCA

#define maxl 25
int timer;
int tin[maxn], tout[maxn], up[maxn][maxl], lvl[maxn];

void dfs_lca(int u, int p, int l) {
    lvl[u] = l;
    tin[u] = ++timer;
    up[u][0] = p;
    frr(i, maxl-1) 
        up[u][i] = up[up[u][i-1]][i-1];
    for (auto v: adj[u]) 
        if (v != p)
            dfs_lca(v, u, l+1);
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = maxl-1; i >= 0; i--) 
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return lvl[v]+lvl[u]-2*lvl[l];
}

// CENTROID DECOMP

int par[maxn], seen[maxn], sz[maxn];

void get_sz(int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        get_sz(v, u);
        sz[u] += sz[v]; 
    }
} 

int centroid_dfs(int u, int p, int n) {
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        if (sz[v] > n/2) return centroid_dfs(v, u, n);
    }
    return u;
}

int find_centroid(int r) {
    get_sz(r, r);
    int n = sz[r];
    return centroid_dfs(r, r, n);
}

void decomposition(int u, int p) {
    int c = find_centroid(u);
    seen[c] = 1;
    for (auto v: adj[c]) {
        if (seen[v]) continue;
        decomposition(v, c);
    }
    if (p == -1) par[c] = c;
    else par[c] = p;
    seen[c] = 0;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs_lca(1, 1, 0);
    decomposition(1, -1);
    ms(mn, INF);

    // for first node
    int p = 1;
    while (1) {
        mn[p] = min(mn[p], dist(p, 1));
        if (p == par[p]) break;
        p = par[p];
    }

    while (m--) {
        int t, v;
        cin >> t >> v;

        if (t == 1) {
            // update
            int p = v;
            while (1) {
                mn[p] = min(mn[p], dist(p, v));
                if (p == par[p]) break;
                p = par[p];
            }
        } else {
            // query
            int ans = mn[v];
            int p = v;
            while (1) {
                ans = min(ans, mn[p]+dist(p, v));
                if (p == par[p]) break;
                p = par[p];
            }
            p(ans);
        }
    }
}
