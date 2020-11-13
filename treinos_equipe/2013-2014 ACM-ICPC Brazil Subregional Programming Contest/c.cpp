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

#define maxn 512

vi adj[maxn];
int age[maxn], vis[maxn], id[maxn], rid[maxn], ans;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    ans = min(ans, age[rid[u]]);
    for (auto v: adj[u]) dfs(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m, q;
    cin >> n >> m >> q;

    frr(i, n) cin >> age[i], id[i] = i, rid[i] = i;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
    }

    while (q--) {
        char op; cin >> op;

        if (op == 'T') {
            int a, b;
            cin >> a >> b;
            swap(id[a], id[b]);
            swap(rid[id[a]], rid[id[b]]);
        }
        else {
            int u;
            cin >> u;
            u = id[u];

            ms(vis, 0);
            ans = INF;

            vis[u] = 1;
            for (auto v: adj[u]) dfs(v);
            if (ans == INF) p("*");
            else            p(ans);
        }
    }
}