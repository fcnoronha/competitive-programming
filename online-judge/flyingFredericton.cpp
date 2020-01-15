// uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2255

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
} e[1009]; 

int dist[101][100009];

void bf(int root, int nv, int ne){

	fr (i, nv)
		fr (j, 100009)
			dist[i][j] = INT_MAX;
	
	dist[0][0] = 0;
	
	frr(i, 100000){

		fr (j, nv) dist[j][i] = dist[j][i-1];

		fr (j, ne){
			int u = e[j].u;
			int v = e[j].v;
			int w = e[j].w;

			if (dist[u][i-1] != INT_MAX && dist[u][i-1] + w < dist[v][i])
				dist[v][i] = dist[u][i-1] + w; 
		}
	}
}

int main(){
	fastio
	
	int t;
	cin >> t;

	frr(to, t){
		int n, m;
		cin >> n;

		map<string, int> aux;
		int cnt = 0;
		string a;
		
		fr(i, n){
			cin >> a;
			aux[a] = cnt++;
		}

		cin >> m;

		fr(i, m){
			cin >> a;
			e[i].u = aux[a];

			cin >> a;
			e[i].v = aux[a];

			cin >> e[i].w;
		}

		int q;
		cin >> q;

		cout << "Scenario #" << to << endl; 
		bf(0, n, m);

		while (q--){
			int stp;
			cin >> stp;
			stp++;

			if (dist[n-1][stp] == INT_MAX) p(No satisfactory flights);
			else cout << "Total cost of flight(s) is $" << dist[n-1][stp] << endl;
			
		}

		if (to < t) cout << endl;
	}
}
