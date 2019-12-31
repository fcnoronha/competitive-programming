// uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2768

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

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

const int INF = 0x3f3f3f3f;

struct edge{
	int u, v, w;
} e[2009]; 

int dist[1001], dist2[1001];

vi g[1009];
int is_in[1009], vis[1009];

bool dfs(int v) {

	if (vis[v]) return is_in[v];
	vis[v] = 1;
	
	for (auto u: g[v]) 
		is_in[v] |= dfs(u);
	
	return is_in[v];
}

void bf(int root, int nv, int ne){

	ms(dist, INF);
	ms(is_in, 0);
	ms(vis, 0);
	
	dist[root] = 0;
	
	vi prt(nv, 0);

	for (int i = 1; i < nv; i++){
		for (int j = 0; j < ne; j++){
			int u = e[j].u;
			int v = e[j].v;
			int w = e[j].w;

			if (dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	int x = 0;
	fr(i, nv) dist2[i] = dist[i];
	for (int j = 0; j < ne; j++){
		int u = e[j].u;
		int v = e[j].v;
		int w = e[j].w;

		if (dist2[u] + w < dist2[v])
			dist2[v] = dist2[u] + w;
	}



	fr(i, nv) {
		if (dist[i] <= dist2[i]) continue;
		x = 1;
		dbg(i);
		is_in[i] = 1;
	} 

	if (!x)	{
		p(impossible);
		return;
	}

	fr(i, nv) dfs(i);
	fr(i, nv) 
		if (is_in[i])
			cout << i << " ";
	cout << endl;
}

int main(){
	fastio
	
	int t;
	cin >> t;

	frr(to, t){
		int n, m;
		cin >> n >> m;

		fr(i, n+2) g[i].clear();

		fr(i, m) {
			cin >> e[i].u >> e[i].v >> e[i].w;
			g[e[i].u].pb(e[i].v);
		}
		
		cout << "Case " << to << ": ";
		bf(0, n, m);
	}
}
