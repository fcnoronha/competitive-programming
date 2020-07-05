//codeforces.com/contest/1364/problem/D

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

int seen[maxn], lvl[maxn], par[maxn], deu;
vi adj[maxn], cc, tree[2];


void dfs(int u, bool flag) {
    
    if (seen[u] || deu) return;
    seen[u] = 1;

    tree[flag].pb(u);
    int idx = -1;
    for (auto v: adj[u]) {
        if (v == par[u]) continue;
        if (seen[v] && (idx == -1 || lvl[v] > lvl[idx])) 
            idx = v;
    }

    if (idx != -1) {
        deu = 1;
        cc.pb(u);
        while (u != idx) {
            u = par[u];
            cc.pb(u);
        }
        return;
    }
    for (auto v: adj[u]) {
        if (par[u] == v) continue;
        par[v] = u;
        lvl[v] = lvl[u]+1;
        dfs(v, !flag);
    }
}

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    fr(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
    
    if (!deu) {
        p(1);
        if (tree[0].size() < tree[1].size()) swap(tree[0], tree[1]);
        fr(i, (k+1)/2) cout << tree[0][i] << " ";
        cout << endl;
        return 0;
    }

    if (cc.size() > k) {
        bool oi = 1;
        vi aux;
        for (int x: cc) {
            if (oi) aux.pb(x);
            oi = !oi;
        }

        while (aux.size() > (k+1)/2) aux.pop_back();

        p(1);
        pv(aux);
        return 0;
    }

    p(2);
    p(cc.size());
    pv(cc);
}
