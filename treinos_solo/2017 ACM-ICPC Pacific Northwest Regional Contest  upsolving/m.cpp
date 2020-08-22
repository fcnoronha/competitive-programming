#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

map<int, bool> vis;
map<int, set<int>> adj, radj, f, r;

void dfs(int u, int ori) {
    if (vis[u]) return;
    vis[u] = 1;

    if (u != ori) {
        f[ori].insert(u);
        r[u].insert(ori);
    }

    for (auto v: adj[u]) 
        dfs(v, ori);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m;
    cin >> n >> m;

    fr(i, m) {
        int a, b;
        cin >> a >> b;
        adj[-a].insert(b);
        adj[-b].insert(a);

        radj[b].insert(-a); 
        radj[a].insert(-b);
    }

    frr(a, n) {
        vis.clear();
        dfs(a, a);
        vis.clear();
        dfs(-a, -a);
    }

    int ans = INF;
    frr(a, n) {
        if (f[a].count(-a) && f[-a].count(a)) {
            ans = 0;
            break;
        }
        
        for (auto x: f[a]) 
            if (x < 0 && f[-a].count(x))
                ans = 1;
        for (auto x: r[a])
            if (x > 0 && r[-a].count(x))
                ans = 1;
    }

    if (ans <= 1) {
        p(ans);
        return 0;
    }

    frr(a, n) {
        int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

        for (auto x: f[a]) if (x < 0) t1 = 1;
        for (auto x: f[-a]) if (x < 0) t2 = 1;
        for (auto x: r[a]) if (x > 0) t3 = 1;
        for (auto x: r[-a]) if (x > 0) t4 = 1;

        if (t1 && t2 && t3 && t4) ans = 2;
    }

    if (ans == INF) ans = -1;
    p(ans);
}
