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

#define maxn 312345
#define maxl 30

int timer;
int tin[maxn], tout[maxn], up[maxn][maxl], h[maxn];
int prt[maxn], ans[maxn], is_at[maxn];
vi adj[maxn];
vector< pair<int, pii> > ltr;

struct Lca {

    void dfs(int u, int p, int hg) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < maxl; ++i)
            up[u][i] = up[up[u][i-1]][i-1];

        for (int v: adj[u]) 
            if (v != p)
                dfs(v, u, hg+1);
        
        tout[u] = ++timer;
        h[u] = hg;
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
};


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ms(ans, -1);

    int n; cin >> n;

    frr(i, n) {
        char op; cin >> op;

        if (op == 'a') {
            int v; cin >> v;

            int cur = is_at[v];
            adj[cur].pb(i);
            prt[i] = cur;
            is_at[i] = i;
        }

        if (op == 'b') {
            int v; cin >> v;

            ans[i] = is_at[i] = is_at[v];
            is_at[i] = prt[is_at[i]];
        }

        if (op == 'c') {
            int v, w; cin >> v >> w;

            is_at[i] = is_at[v];
            ltr.pb({i, {is_at[i], is_at[w]}});
        }
    }

    Lca l;
    l.dfs(0, 0, 0);

    for (auto x: ltr) {

        int i, u, v;
        i = x.f, u = x.s.f, v = x.s.s;

        int anc = l.lca(u, v);
        ans[i] = h[anc];
    }

    frr(i, n) 
        if (ans[i] != -1) 
            p(ans[i]);
}
