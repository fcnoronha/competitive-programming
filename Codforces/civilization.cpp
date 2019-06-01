// codeforces.com/problemset/problem/455/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

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
typedef long double ld;

#define maxn 300100

int n, m, q;
int id[maxn], sz[maxn], mx[maxn];
bool vis[2][maxn]; /* For DFS */
vi adj[maxn]; /* Adjacency list for DFS */

/* DSU */

int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void join(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	/* New biggest road */
	int new_max = max({ mx[p], mx[q], (int)(ceil(mx[q]/2.0) + ceil(mx[p]/2.0) + 1 )});

	id[p] = q;
	sz[q] += sz[p];
	mx[q] = new_max;
}

pii dfs(int v, pii max_val, int idx_vis) {

	pii aux = {-1, -1};

	if (vis[idx_vis][v]) return aux;
	vis[idx_vis][v] = 1;

	/* Getting biggest pair with maximum distance from v */
	for (auto u : adj[v])
		aux = max(aux, dfs(u, {max_val.f + 1, u}, idx_vis));

	aux = max(aux, max_val);
	return aux;
}

int main(){
	fastio

	cin >> n >> m >> q;

	/* Setting up values for DSU */
	frr(i, n) {
		id[i] = i;
		sz[i] = 1;
	}

	/* Reading roads */
	int a, b;
	fr(i, m) {
		cin >> b >> a;
		adj[b].pb(a);
		adj[a].pb(b);
	}

	/* Preprocessing inicial values */

	/* Generating regions */
	frr(u, n)
		for (auto v : adj[u])
			join(u, v);
	ms(mx, 0);

	/* Calculating max path of each region */
	frr(i, n) {

		if (vis[1][i]) continue;

		int a = dfs(i, {0, i}, 0).s;
		int max_calc = dfs(a, {0, a}, 1).f;
		mx[ find(i) ] = max_calc;
	}

	/* Answering queries */
	int op, x, y;
	fr(i, q) {

		cin >> op;
		op--;

		if (!op) {
			cin >> x;
			cout << mx[ find(x) ] << endl;
		}

		else {
			cin >> x >> y;
			join(x, y);
		}
	}
}
