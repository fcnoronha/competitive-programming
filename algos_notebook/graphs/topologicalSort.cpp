// TOPOLOGICAL SORT

#define maxn 1000

vi adj[maxn], order; 
int degree[maxn];

void topoSort(){

	// Receiving graph
	cin >> n >> m;
	fr(i, m){
		int u, v;
		cin >> u >> v;
		degree[v]++; // 'u' must be executted before 'v'
		graph[u].pb(v);
	}

	frr(i, n) if (degree[i] == 0) order.pb(i);
	
	int beg = 0;
	while ((int)order.size() > beg){
		int u = order[beg++];
		for (int v: adj[u]){
			degree[v]--;
			if (degree[v] == 0) order.pb(v);
		}
	}

	if (order.size() < n) {
		cout << "Impossible" << endl;
		return;
	}

	for (auto v: order) cout << v << endl;
}
