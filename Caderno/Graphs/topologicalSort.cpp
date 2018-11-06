// TOPOLOGICAL SORT
// Solves a graph with certain order on its vertices. Uses the ideia
// of steps, you need to solve the predecessor vertice to solve the 
// actual one.

int n; // Number of vertices
int m; // Number of edges

vector<int> graph[n+3];
int order[n+3]; // Inicialize globally for 0's fill
vector<int> list;

void topoSort(){

	// Receiving graph
	cin >> n >> m;
	fr (i, m){
		int u, v;
		cin >> u >> v;

		order[v]++; // 'u' must be executted before 'v'
		graph[u].pb(v);
	}

	// frr because graph is indexed by one
	frr (i, n){
		if (order[i] == 0)
			list.pb(i);
	}

	int beg = 0;
	// BFS style
	while (list.size() > beg){
		int t = list[beg];
		beg++;

		for (int i : graph[t]){
			grau[i]--;
			if (grau[i] == 0) list.push(i);
		}
	}

	if (list.size() < n){
		cout << "Impossible" << endl;
		return;
	}

	while (!list.empty()){
		int v = list.top();
		list.pop();
		cout << v << endl;
	}
}
