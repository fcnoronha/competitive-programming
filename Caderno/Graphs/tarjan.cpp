#include<bits/stdc++.h>
using namespace std;

// Finds strongly connected components (SCC) in a directed graph
// O(V + E)

#define MAXN 1001

vector<int> dfs_num(MAXN, -1);
vector<int> dfs_low(MAXN, 0);
vector<int> s;
vector<int> visited(MAXN, 0);
vector<int> adj[MAXN];

int dfsNC = 0, numSCC = 0;

void tarjan(int u){
	dfs_low[u] = dfs_num[u] = dfsNC++;

	s.push_back(u);
	visited[u] = true;
	for (int j : adj[u]){
		if (dfs_num[j] == -1)
			tarjan(j);

		if (visited[j]) // Propagation
			dfs_low[u] = min(dfs_low[u], dfs_low[j]); 
	}

	if (dfs_low[u] == dfs_num[u]){ // If it is start of SCC
		cout << "SCC : " << ++numSCC;

		while(1){
			int v = s.back();
			s.pop_back();
			visited[v] = 0;
			cout <<  " " << v;
			if (u == v) break; 
		}

		cout << endl;
	} 
}

int main(){

for (int i = 0; i < MAXN; i++)
	if (dfs_num[i] == -1)
		tarjan(i);

}