//codeforces.com/gym/101557/problem/G

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

#define maxn 2512

vector<int> adj[maxn];
int par[maxn], seen[maxn], dist[maxn];

int ans;
pair<int, int> edge_sai, edge_entra;

// return {diametro, vcentro}
pii explore(int ori, int ign, int n) {

    ms(dist, 0);
    int mxd = ori;
    function<void (int, int, int)> dfs_dist = [&](int u, int p, int d) {
        
        if (u == ign) return;
        
        par[u] = p;
        dist[u] = d;

        if (d > dist[mxd]) mxd = u;

        for (auto v: adj[u]) 
            if (v != p)
                dfs_dist(v, u, d+1);
    };
    dfs_dist(ori, ign, 0);
    ms(dist, 0);
    dfs_dist(mxd, mxd, 0);

    int diam = dist[mxd];
    int k = diam/2;
    int center = mxd;
    while (k--) center = par[center];

    // maior profundidade, maior diametro
    return {diam, center};
}

int main() {
    int n;
    cin >> n;

    vector<pii> edg;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        edg.pb({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = INT_MAX;
    for (auto e: edg) {
        
        int u = e.f, v = e.s;
        pii x = explore(u, v, n);
        pii y = explore(v, u, n);

        int mx = max({x.f, y.f, (x.f+1)/2 + (y.f+1)/2 + 1});
        if (mx < ans) {
            ans = mx;
            edge_sai = {u, v};
            edge_entra = {x.s, y.s};
        }
    }

    cout << ans << endl;
    cout << edge_sai.first << " " << edge_sai.second << endl;
    cout << edge_entra.first << " " << edge_entra.second << endl;
}
