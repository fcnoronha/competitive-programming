// http://www.codcad.com/problem/123

#include <bits/stdc++.h>
using namespace std;

int n, m, c, k, w[251][251], visited[251], u, v, p, ori[251], sum_ca, sum_di;
vector<int> adj[251];
int inf = INT_MAX;

int main(){
	bool func = true;

	while (func){
		cin >> n >> m >> c >> k;

		if(n == 0 && m == 0 && c == 0 && k == 0) return 0;

		for(int i = 0; i < m; i++){
			cin >> u >> v >> p;
			w[u][v] = w[v][u] = p;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<int> dist(n+2, inf);

		priority_queue<pair<int, int> > q;
		q.push(make_pair(0, c-1));
		dist[c-1] = 0;

		for(int i = c-2; i >= 0; i--){
			dist[i] = dist[i+1] + w[i][i+1];
			//cout << dist[i] << endl;
		}

		while(!q.empty()){
			int v = q.top().second;
			q.pop();
			//cout << v << endl;

			if(visited[v] == 1) continue;
			visited[v] = 1;

			for(int u : adj[v]){
				if(dist[u] > dist[v] + w[u][v]){
					if(u > c-1) dist[u] = dist[v] + w[u][v];
					q.push(make_pair(-dist[u], u));
				}
			}
		}

		cout << dist[k] << endl;
	}
}