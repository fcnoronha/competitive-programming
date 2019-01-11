// codeforces.com/gym/101808/problem/K

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

#define MAXN 100090
#define MAXL 18 

vector<pair<int, ll>> adj[MAXN];
int lvl[MAXN];
int parent[MAXN];
int anc[MAXN][MAXL];
ll acost[MAXN];
bool vis[MAXN];

int au, av;
ll aw;

void dfs(int u){

	for (auto v : adj[u]){

		if (v.f == parent[u]) continue;

		if (vis[v.f]){
			au = u;
			av = v.f;
			aw = v.s;

			continue;
		}

		acost[v.f] = acost[u] + v.s;
		parent[v.f] = u; 
		lvl[v.f] = lvl[u] + 1;
		vis[v.f] = 1;
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

ll dist(int a, int b){
	return acost[a] + acost[b] - 2ll*acost[lca(a, b)];
}

int main(){

	fastio
	int t;
	cin >> t;

	while (t--){
		int N, n, m;
		cin >> n >> m;

		frr(i, n) adj[i].clear();

		fr(i, n){
			int a, b;
			ll c;
			cin >> a >> b >> c;

			adj[a].pb({b, c});
			adj[b].pb({a, c});
		}

		frr(i, n){
			lvl[i] = -1;
			parent[i] = vis[i] = 0;
			acost[i] = 0ll;
		}

		int root = 1; 
		vis[root] = 1;
		lvl[root] = 1;

		dfs(root);

		frr(i, n)
			anc[i][0] = parent[i];

		frr(j, MAXL-1)
			frr(i, n)
				anc[i][j] = anc[anc[i][j-1]][j-1];


		fr(i, m){
			int a, b;
			cin >> a >> b;

			ll ans = dist(a, b);
			ll ans2 = dist(a, au) + dist(av, b) + aw;
			ans = min(ans, ans2);

			ll ans3 = dist(a, av) + dist(au, b) + aw;
			ans = min(ans, ans3);

			cout << ans << endl;
		}
	}
}
