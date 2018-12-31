// www.codcad.com/problem/124

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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

int age[509], mp[509];
vector<int> adj[509];
bool visited[509];

int dfs(int v){

	int ret = 666;

	stack<int> q;
	for (auto u : adj[v]) q.push(u);
	visited[v] = 1;

	while(!q.empty()){

		int act = q.top();
		q.pop();

		if (visited[act]) continue;
		visited[act] = 1;

		ret = min(ret, age[act]);

		for (auto u : adj[act]) q.push(u);
	}

	return ret;
}

int main(){
	fastio
		
	ll n, m, qry;
	while (cin >> n >> m >> qry && n != EOF){

		frr(i, n) cin >> age[i], mp[i] = i;
		frr(i, n) adj[i].clear();

		int x, y;
		fr(i, m){
			cin >> x >> y;
			adj[y].pb(x);
		}

		char op;
		fr(i, qry){
			cin >> op;

			if (op == 'T'){
				int a, b;
				cin >> a >> b;
				swap(age[a], age[b]);
				swap(mp[a], mp[b]);
			}

			else {
				frr(i, n) visited[i] = false;

				int e;
				cin >> e;

				e = mp[e];

				int ans = dfs(e);
				if (ans == 666) cout << "*" << endl;
				else cout << ans << endl;
			}
		}
	}
}
