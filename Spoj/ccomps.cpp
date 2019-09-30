//www.spoj.com/problems/CCOMPS/

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

#define maxn 100009

vi adj[maxn];
bool vis[maxn];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto x : adj[u])
        dfs(x);
}

int main(){
    fastio

    int n, m;
    cin >> n >> m;

    int u, v;
    fr(i, m) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int cnt = 0;
    fr(i, n) {
        if (!vis[i])
            dfs(i), cnt++;
    }

    cout << cnt << endl;
}
