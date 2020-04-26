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

map<int, set<int>> mp[maxn];
int t[maxn], ans[maxn];
vi adj[maxn];

void dfs(int u, int prt) {

    int mt = t[u];
    for (auto v: adj[u]) if (v != prt) dfs(v, u);
        
    for (auto x: mp[u][mt]) ans[x] = 1;
    mp[u][mt].clear();

    for (auto v: adj[u]) {
        if (v == prt) continue;

        for (auto x: mp[v][mt]) ans[x] = 1;
        mp[v][mt].clear();

        if (mp[u] > mp[v]) swap(mp[u], mp[v]);
        for (auto &aux: mp[v]) {
            int tp = aux.f;
            if (mp[u][tp].size() < aux.s.size()) swap(aux.s, mp[u][tp]);
            for (auto x: aux.s) {
                if (mp[u][tp].find(x) == mp[u][tp].end()) mp[u][tp].insert(x);
                else mp[u][tp].erase(x);
            }
            aux.s.clear();
        }
        mp[v].clear();
    } 
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    frr(i, n) cin >> t[i];
    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    fr(i, m) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b && t[a] != c) continue; 
        mp[a][c].insert(i);
        mp[b][c].insert(i);
    }

    //frr(i, n) for (auto x: mp[i]) dbg(x.f);

    dfs(1, 1);

    fr(i, m) cout << ans[i];
    cout << endl;
}
