//codeforces.com/problemset/problem/609/E

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

#define maxn 212345

///////////// KRUSKAL /////////////////////////q

typedef struct edge {
    ll dis;
    int u, v;
} t_edge;

bool comp(t_edge a, t_edge b){ 
	return a.dis < b.dis; 
}

int id[maxn], sz[maxn];
t_edge edg[maxn], mst[maxn], ori[maxn];

int find(int p){
    if (id[p] == p) return p;
    return id[p] = find(id[p]); 
}

void uni(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}

////////////////////////////// LCA ////////////////////

#define maxl 25 

int timer;
int tin[maxn], tout[maxn], up[maxn][maxl];
ll mx[maxn][maxl];
vector<pll> adj[maxn];

void dfs_lca(int v, int p, ll c) {
    tin[v] = ++timer;
    up[v][0] = p;
    mx[v][0] = c;
    for (int i = 1; i < maxl; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        mx[v][i] = max(mx[v][i-1], mx[up[v][i-1]][i-1]);
    }

    for (auto x : adj[v]) {
        int u = x.f;
        if (u != p) {
            dfs_lca(u, v, x.s);
        }
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

ll get_max(int v, int l) {

    ll mxc = -LINF;
    for (int i = maxl-1; i >= 0; i--) {
        if (v == l) break;
        if (!is_ancestor(l, up[v][i])) continue;
        mxc = max(mxc, mx[v][i]);
        v = up[v][i];
    }
    return mxc;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    fr(i, m) {
        cin >> edg[i].u >> edg[i].v >> edg[i].dis;
        ori[i] = edg[i];
    }

    frr(i, n) id[i] = i, sz[i] = 1;
    sort(edg, edg+m, comp);
    int mst_sz = 0;
    fr(i, m) {
        if (find(edg[i].u) == find(edg[i].v)) continue;
        uni(edg[i].u, edg[i].v);           
        mst[mst_sz++] = edg[i];
    }

    ll mst_cst = 0ll;
    fr(i, mst_sz) {
        int u = mst[i].u, v = mst[i].v;
        ll cst = mst[i].dis;
        adj[u].pb({v, cst});
        adj[v].pb({u, cst});
        mst_cst += cst;
        //cout << u << " " << v << "\n"; 
    }

    dfs_lca(1, 1, 0);

    fr(i, m) {
        auto e = ori[i];
        int l = lca(e.u, e.v);
        //cout << "u> " << e.u << " v> " << e.v << " l> " << l << endl; 
        ll ans = mst_cst + e.dis;
        ans -= max(get_max(e.u, l), get_max(e.v, l));
        p(ans);
    }
}
