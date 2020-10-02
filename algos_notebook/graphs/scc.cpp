// TARJAN
// Finds strongly connected components (SCC) in a directed graph
// O(V + E)

#define maxn 1001

int dfs_num[maxn], dfs_low[maxn];
bool vis[maxn];
vector<int> s;
vector<int> adj[maxn];

int dfsNC, numSCC;

void tarjan(int u){
	dfs_low[u] = dfs_num[u] = dfsNC++;
	s.push_back(u);
	vis[u] = 1;
	for (int to : adj[u]){
		if (dfs_num[to] == -1)
			tarjan(to);
		if (vis[to])
            dfs_low[u] = min(dfs_low[u], dfs_low[to]);
	}
	if (dfs_low[u] == dfs_num[u]) { // If it is start of SCC
		cout << "SCC : " << ++numSCC;
		while(1){
			int v = s.back();
			s.pop_back();
			vis[v] = 0;
			cout <<  " " << v;
			if (u == v) break;
		}
		cout << endl;
	}
}

void find_sccs() {

    memset(dfs_num, -1, sizeof(dfs_num));
    memset(vis, 0, sizeof(vis));

    dfsNC = numSCC = 0;

    for (int i = 0; i < maxn; i++)
    	if (dfs_num[i] == -1)
    		tarjan(i);
}
