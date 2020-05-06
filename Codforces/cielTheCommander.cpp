//codeforces.com/contest/321/problem/C

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

vector<int> adj[maxn];
int seen[maxn], sz[maxn], ans[maxn];

void get_sz(int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue; 
        get_sz(v, u);
        sz[u] += sz[v];
    }
}

int centroid_dfs(int u, int p, int n) {
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        if (sz[v] > n/2) return centroid_dfs(v, u, n);
    }
    return u;
}

int find_centroid(int root) {
    get_sz(root, root);
    int n = sz[root];
    return centroid_dfs(root, root, n);
}

void decomposition(int u, int lvl) {
    int c = find_centroid(u);
    seen[c] = 1;
    for (auto v: adj[c]) {
        if (seen[v]) continue;
        decomposition(v, lvl+1);
    }
    ans[c] = lvl;
    seen[c] = 0;
}

int main() {
    fastio;

    int n;
    cin >> n;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    decomposition(1, 0);
    frr(i, n) cout << char('A'+ans[i]) << " ";
    cout << endl;
}
