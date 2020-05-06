//www.spoj.com/problems/QTREE5/

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
multiset<int> mn[maxn];
int tp[maxn];

// lca

#define maxl 19

int timer, tin[maxn], tout[maxn], up[maxn][maxl], lvl[maxn];

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
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
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
    return lvl[u]+lvl[v]-2*lvl[l];
}

// centroid decomp

int par[maxn], seen[maxn], sz[maxn];

void get_sz(int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]){
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

    int n;
    cin >> n;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs_lca(1, 1, 0);
    decomposition(1, -1);

    int q;
    cin >> q;
    while (q--) {
        int t, v;
        cin >> t >> v;

        if (!t) {
            // update
            if (tp[v]) {
                // turn off
                tp[v] = 0;
                int p = v;
                while (1) {
                    mn[p].erase(mn[p].find(dist(p, v)));
                    if (p == par[p]) break;
                    p = par[p];
                }
            }
            else {
                // turn on
                tp[v] = 1;
                int p = v;
                while (1) {
                    mn[p].insert(dist(p, v));
                    if (p == par[p]) break;
                    p = par[p];
                }
            }

        }
        else {
            // query
            int ans = INF, p = v;
            while (1) {
                if (mn[p].size()) {
                    int x = *mn[p].begin();
                    ans = min(ans, x+dist(v, p));
                }
                if (p == par[p]) break;
                p = par[p];
            }
            if (ans == INF) p(-1);
            else p(ans);
        }
    }
}
