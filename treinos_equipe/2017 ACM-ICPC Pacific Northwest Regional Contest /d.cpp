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

#define maxn 50009

vector<pii> adj[maxn];

int vis[maxn], ans[maxn];

void dfs(int u, int prt) {
    if (vis[u] == 2) return;
    vis[u]++;
    ans[u]++;

    for (auto x: adj[u])
        if (x.f != prt)
            dfs(x.f, u);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n;
    cin >> n;
    fr(i, n-1) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }

    frr(v, n) {
        map<int, vi> mp;
        for (auto x: adj[v])
            mp[x.s].pb(x.f);

        for (auto x: mp) 
            if (x.s.size() > 1)
                for (auto u: x.s)
                    dfs(u, v);
    }

    int cnt = 0;
    frr(v, n) cnt += ans[v] == 0;
    cout << cnt << '\n';
    frr(v, n) if (ans[v] == 0) cout << v << '\n';
}
    