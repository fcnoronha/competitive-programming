//br.spoj.com/problems/TUBOS/

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

vi adj[maxn];
bool visited[maxn];
int tin[maxn], low[maxn];
int timer, cnt, n, m;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                cnt++;
        }
    }
}

void find_bridges() {
    timer = cnt = 0;
    ms(tin, -1);
    ms(low, -1);
    ms(visited, 0);
    for (int i = 1; i < n; ++i)
        if (!visited[i])
            dfs(i);
}

int main(){
    fastio

    while (cin >> n >> m && (n || m)) {

        frr(i, n) adj[i].clear();

        int u, v;
        fr(i, m) {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        find_bridges();
        if (cnt) p("N");
        else p("S");
    }
}
