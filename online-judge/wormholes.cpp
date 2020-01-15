// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499

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
	

	for (int i = 1; i < nv; i++){
		for (int j = 0; j < ne; j++){
			int u = e[j].u;
			int v = e[j].v;
			int w = e[j].w;

			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	for (int i = 0; i < ne; i++){
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;

		if (dist[u] != INT_MAX && dist[u] + w < dist[v]){
			p(possible);
			return;
		}
	}

	p(not possible);
	return;
}

int main(){
	fastio
	
	int t;
	cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;

		fr(i, m)
			cin >> e[i].u >> e[i].v >> e[i].w;
		
		bf(0, n, m);
	}
}
