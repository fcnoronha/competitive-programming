// www.codcad.com/problem/103

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
	
	int n; cin >> n;

	vector<int> adj[n+1];
	fr(i, n){
		int u, v;
		cin >> u >> v;

		adj[v].pb(u);
	}

	int cnt[n+1];
	frr(i, n) cnt[i] = 0;

	queue<int> q;
	q.push(0);

	while (!q.empty()){
		int v = q.front();
		q.pop();

		for (auto u : adj[v]){
			cnt[v]++;
			q.push(u);
		}
	}

	frr(i, n){

		fr(j, adj[i].size()){
			if (j == 0) continue;
			if (cnt[adj[i][j] != cnt[adj[i][j-1]]]){
				cout << "mal" << endl;
				return 0;
			}
		}
	}

	cout << "bem" << endl;
	return 0;
}
