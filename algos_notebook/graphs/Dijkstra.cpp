// DIJKSTRA

#define maxn 1000

int n, m, s, t, b, w[maxn][maxn], vis[maxn];
vector<int> adj[maxn]; 

void dijkstra(int root) {

	vector<int> dist(n+2, inf);

	set< pair<int, int> > st; 
	st.insert({0, root});
	dist[root] = 0;

	while (!st.empty()) { 

		int v = *(st.begin()).first;
		st.erase(st.begin());

		if (vis[v] == 1) continue; 
		vis[v] = 1; 

		for (int u: adj[v]) {
			if (dist[u] > dist[v] + w[v][u]){
				dist[u] = dist[v] + w[v][u]; 
				st.insert({dist[u], u});
			}
		}
	}
}
