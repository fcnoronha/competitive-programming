//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=551
// 610 - street directions

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 1009

vi adj[maxn]; // adjacency list of graph

bool vis[maxn];
bool put[maxn][maxn];

int tin[maxn], low[maxn];
int timer, t, n, m;

vector<pii> ans;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                ans.pb({to, v});
                ans.pb({v, to});
                put[to][v] = put[v][to] = 1;
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    ms(tin, -1);
    ms(low, -1);
    ms(vis, 0);
    ms(put, 0);

    for (int i = 0; i < n; ++i)
        if (!vis[i])
            dfs(i);
}

void dfs2(int v) {

    if (vis[v]) return;
    vis[v] = 1;

    for (auto u : adj[v]) {

        if (!put[u][v] && !put[v][u]) {
            ans.pb({v, u});
            put[u][v] = put[v][u] = 1;
        }

        dfs2(u);
    }
}

int main(){
    fastio

    while (cin >> n >> m && (n || m)) {

        fr(i, n) adj[i].clear();
        ans.clear();

        int u, v;
        fr(i, m) {
            cin >> u >> v;
            u--, v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        find_bridges();
        ms(vis, 0);

        dfs2(0);

        cout << ++t << "\n\n";
        for (auto x : ans)
            cout << x.f+1 << " " << x.s+1 << "\n";
        cout << "#\n";
    }
}
