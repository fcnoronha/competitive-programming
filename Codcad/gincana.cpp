// www.codcad.com/problem/119

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
	int n, m;
	cin >> n >> m;

	vector<int> adj[n+1];
	vector<bool> visited(n+1, false);

	fr(i, m){
		int a, b;
		cin >> a >> b;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	int ans = 0;
	frr(i, n){

		if (visited[i]) continue;
		ans++;

		queue<int> q;
		q.push(i);

		while (!q.empty()){

			int v = q.front();
			q.pop();

			if (visited[v]) continue;
			visited[v] = 1;

			for (auto u : adj[v])
				q.push(u);
		}
	}

	cout << ans << endl;
}
