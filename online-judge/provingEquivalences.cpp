//icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2288
// 4287 - Proving equivalences

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

#define maxn 20009

int dfs_num[maxn], dfs_low[maxn], scc[maxn], indeg[maxn], outdeg[maxn];
bool vis[maxn];
vector<int> s;
vector<int> adj[maxn];

int dfsNC, numSCC, n, m;

void tarjan(int u){
	dfs_low[u] = dfs_num[u] = dfsNC++;
	s.push_back(u);
	vis[u] = 1;
	for (int to : adj[u]){
		if (dfs_num[to] == -1)
			tarjan(to);
        if (vis[to])
		      dfs_low[u] = min(dfs_low[u], dfs_low[to]);
	}
	if (dfs_low[u] == dfs_num[u]) { // If it is start of SCC
		while(1){
			int v = s.back();
			s.pop_back();
			vis[v] = 0;
			scc[v] = numSCC;
			if (u == v) break;
		}
        numSCC++;
	}
}

void find_sccs() {

    ms(dfs_num, -1);
    ms(dfs_low, 0);
    ms(vis, 0);
    ms(indeg, 0);
    ms(outdeg, 0);

    numSCC = dfsNC = 0;

    for (int i = 0; i < n; i++)
    	if (dfs_num[i] == -1)
    		tarjan(i);
}

int main(){
    fastio

    int t;
    cin >> t;

    while (t--) {

        cin >> n >> m;

        fr(i, n) adj[i].clear();
        s.clear();

        int u, v;
        fr(i, m) {
            cin >> u >> v;
            u--, v--;
            adj[u].pb(v);
        }

        find_sccs();

        fr(v, n) {
            for (auto u : adj[v]) {
                if (scc[u] == scc[v]) continue;
                outdeg[scc[v]]++;
                indeg[scc[u]]++;
            }
        }

        int ans = 0;
        int aux = 0;
        fr(i, numSCC)
            aux += (indeg[i] == 0);
        ans = aux;
        aux = 0;
        fr(i, numSCC)
            aux += (outdeg[i] == 0);
        ans = max(ans, aux);

        if (numSCC <= 1)
            ans = 0;

        cout << ans << endl;
    }
}
