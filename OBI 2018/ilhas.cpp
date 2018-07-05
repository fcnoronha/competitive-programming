#include <bits/stdc++.h>
using namespace std;

int w[1001][1001], visited[100001], u, v, p, s, n, m;

int inf = INT_MAX;

vector<int> adj[1001];

int main(){
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		cin >> u >> v >> p;

		w[u][v] = w[v][u] = p;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cin >> s;

	vector<int> dist(n+1, inf);

	priority_queue<pair<int,int> > q;
	q.push(make_pair(0, s));
	dist[s] = 0;

	while(!q.empty()){
		int v = q.top().second;
		q.pop();
		if(visited[v] == 1) continue;
		visited[v] = 1;
		for(int u : adj[v]){
			if(dist[u] > dist[v] + w[v][u]){
				dist[u] = dist[v] + w[v][u];
				q.push(make_pair(-dist[u], u));
			}
		}
	}

	int mx = 0, mi = inf;

	for(int i = 0; i < n+1; i++){
		if(i == 0 or i == s) continue;

		if(dist[i] < mi) mi = dist[i];
		if(dist[i] > mx) mx = dist[i];
	}

	cout << mx - mi << endl;
}