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

ll dist[209];
vector<bool> caralho;
vector<oi> e;

void bf(int root, int nv, int ne){

	for (int i = 1; i <= nv; i++)
		dist[i] = LLONG_MAX;
	
	dist[root] = 0ll;
	
	for (int i = 1; i < nv; i++){

		for (int j = 0; j < ne; j++){
			int u = e[j].u;
			int v = e[j].v;
			int w = (ll)e[j].w;

			w = pow(w, 3ll);

			if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	for (int i = 0; i < ne; i++){
		int u = e[i].u;
		int v = e[i].v;
		int w = (ll)e[i].w;

		w = pow(w, 3ll);

		if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]){
			dist[v] = dist[u] + w;
			caralho[v] = (1==1);
		}
	}
}

int main(){
	fastio
	
	int cnt = 0;
	int n;

	while (cin >> n && n != EOF){

		caralho.resize(n+1);
		int b[n+1];
		frr(i, n) cin >> b[i], caralho[i] = false;

		int m;
		cin >> m;

		e.clear();

		fr(i, m){
			int u, v;
			cin >> u >> v;

			e.pb({u, v, b[v]-b[u]});
		}

		bf(1, n, m);

		int q;
		cin >> q;

		cout << "Set #" << ++cnt << endl;
		while (q--){
			int x;
			cin >> x;

			if (dist[x] < 3 || dist[x] == LLONG_MAX || caralho[x]) p(?);
			else cout << dist[x] << endl;
		}
	}
}
