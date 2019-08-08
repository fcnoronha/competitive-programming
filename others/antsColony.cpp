// www.urionlinejudge.com.br/judge/en/problems/view/1135

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define MAXN 100009 
#define MAXL 19

vector<pair<int, ll>> adj[MAXN]; // vextex , distnace
int parent[MAXN];
int lvl[MAXN];
int anc[MAXN][MAXL];
bool visited[MAXN];
ll tcost[MAXN];

void dfs(int u){

	for (auto v : adj[u]){

		if (lvl[v.f] != -1 || visited[v.f]) continue;

		tcost[v.f] = ll(tcost[u] + v.s);

		parent[v.f] = u; 
		lvl[v.f] = lvl[u] + 1;
		dfs(v.f);
	}
}

int lca(int u, int v){

	if (lvl[u] < lvl[v]) swap(u, v);

	for (int i = MAXL-1; i >= 0; i--)
		if (lvl[u] - (1 << i) >= lvl[v])
			u = anc[u][i];

	if (u == v) return v;

	for (int i = MAXL-1; i >= 0; i--)
		if (anc[u][i] != -1 && anc[u][i] != anc[v][i]){
			u = anc[u][i];
			v = anc[v][i];
		}

	return anc[u][0];
}

int main(){

	fastio;
	ll n;

	while (cin >> n && n > 0){
		ll N = n;

		fr(i, n+2) adj[i].clear();

		frr(i, n-1){
			ll a, l;
			cin >> a >> l;

			adj[i].pb({a, l});
			adj[a].pb({i, l});
		}

		for(int i = 0; i < N+4; i++)
			lvl[i] = -1, visited[i] = 0, tcost[i] = 0ll;

		int root = 0; 
		lvl[root] = 0;

		dfs(root);

		for (int i = 0; i < N+3; i++)
			for (int j = 0; j < MAXL; j++)
				anc[i][j] = -1;

		for (int i = 1; i <= N; i++)
			anc[i][0] = parent[i];

		for (int j = 1; j < MAXL; j++)
			for (int i = 1; i <= N; i++)
				if (anc[i][j-1] != -1)
					anc[i][j] = anc[anc[i][j-1]][j-1];

		int q;
		cin >> q;
		vl ansv;
		fr(i, q){
			int a, b;
			cin >> a >> b;

			ll ans = tcost[a] + tcost[b];
			ans -= 2ll*tcost[lca(a, b)];

			ansv.pb(ans);
		}

		fr(i, q){
			cout << ansv[i];
			if (i < q-1) cout << " ";
			else cout << endl;
		}
	}
}

