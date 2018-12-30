// www.codcad.com/problem/141

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	fastio

	ll dist[259][259];

	frr(i, 250) frr(j,250) dist[i][j] = INT_MAX;

	ll m, n, u, v, w;
	cin >> n >> m;

	fr(i, m) {
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}

	frr(k, n) {
		frr(i, n) {
			frr(j, n){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	ll ans = LLONG_MAX, aux = -1;

	frr(i, n) {
		frr(j, n){
			if(i == j) continue;
			aux = max(aux, dist[i][j]);
		}
		ans = min(ans, aux);
		aux = -1;
	}

	cout << ans << endl;
		
}
