// www.urionlinejudge.com.br/judge/en/problems/view/1227

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

#define maxn 109

int n, a, b, c;
vi adj[maxn];
bool vis[maxn];
int sz[maxn];

int cnt_f, pb;

void dfs(int v, int p, int h) {

	// v - actual | p - parent | h - heigth

	if (vis[v]) return;
	vis[v] = 1;

	for (auto u : adj[v])
		dfs(u, v, h+1);

	// Cleaning leafs and keeping track of a
	if (sz[v] == 1 && v != b && v != c) {
		sz[p]--;
		if (a == v) a = p;
	}

	if (v == b) cnt_f = h;
	if (v == a) pb = h;
}

int main(){

	while (scanf("%d %d %d %d", &n, &a, &b, &c) == 4) {

		// Cleaning up
		frr(i, n)
			adj[i].clear();
		ms(vis, 0);
		ms(sz, 0);

		int u, v;
		fr(i, n-1){
			cin >> u >> v;
			adj[u].pb(v); sz[u]++;
			adj[v].pb(u); sz[v]++;
		}

		dfs(c, 0, 0);

		cout << setprecision(6) << fixed << (1.0*pb)/(cnt_f*1.0) << endl;
	}
}
