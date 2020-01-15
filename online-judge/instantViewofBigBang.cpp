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
int vis[1009];

void dfs(int v) {

	if (vis[v]) return;
	vis[v] = 1;
	
	for (auto u: g[v]) 
		dfs(u);
}

void bf(int root, int nv, int ne){

	ms(dist, INF);
	ms(vis, 0);
	
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
	for (int j = 0; j < ne; j++){
		int u = e[j].u;
		int v = e[j].v;
		int w = e[j].w;

		if (dist[u] + w < dist[v]) {
			x = 1;
			dist[v] = dist[u]+w;
			dfs(u);
		}
	}

	if (!x)	{
		p(impossible);
		return;
	}

	x = 0;
	fr(i, nv) 
		if (vis[i]) {
			if (x) cout << " ";
			else x = 1;
			cout << i;
		}
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
			cin >> e[i].v >> e[i].u >> e[i].w;
			g[e[i].u].pb(e[i].v);
		}
		
		cout << "Case " << to << ": ";
		bf(0, n, m);
	}
}
