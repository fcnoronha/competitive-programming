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


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 5002
#define maxl 13

struct mapp {
    int mp[maxn][maxn];

    void upd(int u, int v, int val) {
        mp[u][v] = max(mp[u][v], val);
        mp[v][u] = max(mp[v][u], val);
    }
};


int timer;
int tin[maxn], tout[maxn], up[maxn][maxl];

mapp f;
vector<pii> edges;
int prt[maxn], n, m;
vi adj[maxn];

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i < maxl; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) 
        if (u != p)
            dfs(u, v);
    
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


void sobe(int u, int lc, int g) {

    if (u == lc) return;
    f.upd(u, up[u][0], g);
    sobe(up[u][0], lc, g);
}

int check(int u, int lc) {

    if (u == lc) return INF;
    return min(f.mp[u][up[u][0]], check(up[u][0], lc));
}

int main(){
    fastio;

    cin >> n;
    int u, v, g;
    fr(i, n-1) {
        cin >> u >> v;
        edges.pb({u, v});
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 1);

    cin >> m;
    vector< pair<int, pii> > qrs;
    fr(i, m) {
        cin >> u >> v >> g;

        int l = lca(u, v);
        sobe(u, l, g);
        sobe(v, l, g);

        qrs.pb({g, {u, v}});
    }

    int deu = 1;
    for (auto q: qrs) {
        u = q.second.first;
        v = q.second.second;
        g = q.first;

        int l = lca(u, v);

        int mn = min(check(u, l), check(v, l));
        if (mn > g) deu = 0;
    }

    if (!deu) {
        p("-1");
        return 0;
    }

    for (auto e: edges) 
        if (f.mp[e.first][e.second] == 0)
            f.mp[e.first][e.second] = 1000000;

    for (auto e: edges) cout << f.mp[e.first][e.second] << " ";
    cout << endl;
}

