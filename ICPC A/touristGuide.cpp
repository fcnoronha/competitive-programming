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

typedef struct edge{
	int u, v, w;
} oi;

ll dist[109];
vector<oi> e;

void bf(int root, int nv, int ne){

	frr(i, nv)
		dist[i] = LLONG_MAX;
	
	dist[root] = LLONG_MAX-1;
	
	frr(i, nv-1){

		fr(j, ne){
			int u = e[j].u;
			int v = e[j].v;
			ll w = (ll)e[j].w;

			if (dist[u] == LLONG_MAX) continue;

			// trabalhar no desenpate
			w = min(w, dist[u]);

			if (w > dist[v] || dist[v] == LLONG_MAX)
				dist[v] = w;
		}
	}
}

int main(){
	fastio
	
	int cnt = 0;
	int n, r;

	while (cin >> n >> r && n && r){

		e.clear();

		fr(i, r){
			int u, v, w;
			cin >> u >> v >> w;
			w--;
			e.pb({u, v, w});
			e.pb({v, u, w});
		}

		r *= 2;

		int src, d, t;
		cin >> src >> d >> t; 

		fr(i, r) e[i].w = min(e[i].w, t);

		bf(src, n, r);

		cout << "Scenario #" << ++cnt << endl;
		cout << "Minimum Number of Trips = " << ceil((double)t/dist[d]) << endl;
		cout << endl;
	}
}
