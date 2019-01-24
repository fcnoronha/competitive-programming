// uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2768

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

struct edge{
	int u, v, w;
} e[2009]; 

int dist[1001];

void bf(int root, int nv, int ne){

	for (int i = 0; i < nv; i++)
		dist[i] = INT_MAX;
	
	dist[root] = 0;
	
	vi prt(nv, 0);

	for (int i = 1; i < nv; i++){
		for (int j = 0; j < ne; j++){
			int u = e[j].u;
			int v = e[j].v;
			int w = e[j].w;

			if (dist[u] != INT_MAX && dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				prt[u] = v;
			}
		}
	}

	int x = 0;

	// Cant undestand what the answer should be

	for (int i = 0; i < ne; i++){
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;

		if (dist[u] != INT_MAX && dist[u] + w < dist[v]){
			cout << u << " ";
			x = 1;
			dist[v] = dist[u] + w;
		}
	}

	if (!x)	p(impossible);
	else cout << endl;

	fr(i, nv)
		x = prt[x];

	vi cycle;
	for (int v = x; ; v = prt[v]){
		cycle.pb(v);
		if (v == x && cycle.size() > 1)
			break;
	}

	reverse(all(cycle));
	//pv(cycle);
}

int main(){
	fastio
	
	int t;
	cin >> t;

	frr(to, t){
		int n, m;
		cin >> n >> m;

		fr(i, m)
			cin >> e[i].u >> e[i].v >> e[i].w;
		
		cout << "Case " << to << ": ";
		bf(0, n, m);
	}
}
