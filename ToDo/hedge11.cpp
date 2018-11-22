// https://br.spoj.com/problems/HEDGE11/

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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	ll r, c, q, u, v;

	while(cin >> r >> c >> q && r != 0 && c != 0 && q != 0){

		vi adj[r+2];
		vi dfs_min(r+2, INT_MAX);

		fr(i, c){
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		frr(i, r){
			dfs_min[i] = min(i, dfs_min[i]);

			for (int u : adj[i])
				if (u == i+1)
					dfs_min[u] = dfs_min[i];
		}		

		fr(i, q){
			cin >> u >> v;
			if (u > v) swap(u,v);
			//dbg(dfs_min[v]);
			if (dfs_min[v] <= u)
				cout << 'Y' << endl;
			else
				cout << 'N' << endl;
		}

		cout << '-' << endl;
	}
}
