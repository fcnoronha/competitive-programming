// acm.timus.ru/problem.aspx?num=1471

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

#define MAXN 50050 
#define MAXL 30 

vector<pair<int, ll>> adj[MAXN];
int lvl[MAXN];
int parent[MAXN];
int anc[MAXN][MAXL];
ll acost[MAXN];
bool vis[MAXN];

void dfs(int u){

	vis[u] = 1;

	for (auto v : adj[u]){

		if (lvl[v.f] != -1 || vis[v.f]) continue;

		acost[v.f] = ll(acost[u] + v.s);
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

	fastio

	int N, n;
	cin >> N;
	n = N;

	fr(i, n-1){
		int u, v;
		ll w;
		cin >> u >> v >> w;

		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}

	for(int i = 0; i <= N; i++)
		lvl[i] = -1, vis[i] = 0;

	int root = 0; 
	lvl[root] = 0;
	acost[root] = 0;

	dfs(root);

	for (int i = 0; i <= N; i++)
		for (int j = 0; j < MAXL; j++)
			anc[i][j] = -1;
	
	for (int i = 0; i <= N; i++)
		anc[i][0] = parent[i];

	for (int j = 1; j < MAXL; j++)
		for (int i = 0; i <= N; i++)
			if (anc[i][j-1] != -1)
				anc[i][j] = anc[anc[i][j-1]][j-1];

	int m;
	cin >> m;

	fr(i, m){
		int a, b;
		cin >> a >> b;

		ll ans = acost[a] + acost[b] - 2ll*acost[lca(a, b)];
		cout << ans << endl;
	}
}
