// http://www.codcad.com/problem/123

#include <bits/stdc++.h>
using namespace std;

int inf = INT_MAX;

int main(){
	bool func = true;

	while (func){
		int n = 0, m = 0, c = 0, k = 0, u = 0, v = 0, p = 0;
		int visited[251], w[251][251];

		for(int i = 0; i < 251; i++){
			visited[i] = 0;
			for(int j = 0; j < 251; j++){
				w[i][j] = 0;
			}
		}

		cin >> n >> m >> c >> k;

		if(n == 0 && m == 0 && c == 0 && k == 0) return 0;

		vector<int> adj[251];
		vector<int> dist(n+2, inf);

		for(int i = 0; i < m; i++){
			cin >> u >> v >> p;
			w[u][v] = w[v][u] = p;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}		

		priority_queue<pair<int, int> > q;
		q.push(make_pair(0, c-1));
		dist[c-1] = 0;

		for(int i = c-2; i >= 0; i--){
			dist[i] = dist[i+1] + w[i][i+1];
			//cout << dist[i] << endl;
			q.push(make_pair(-dist[i], i));
		}

		while(!q.empty()){
			int v = q.top().second;
			q.pop();

			//cout << "v: " << v << " dist[v]: " << dist[v] << endl;
			if(visited[v] == 1) continue;
			visited[v] = 1;

			for(int u : adj[v]){
				//cout << "u: " << u << " dist[u]: " << dist[u] << " w: "  << w[u][v] << endl;
				if(dist[u] > dist[v] + w[u][v]){
					if(u > c-1) dist[u] = dist[v] + w[u][v];
					q.push(make_pair(-dist[u], u));
				}
			}
		}
		cout << dist[k] << endl;
	}
}