// LCA - LOWEST COMMON ANCESTOR

// O(n*logn)

// First, we have to find the parent of every node

#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010 // Nodes - TO BE DEFINED
#define MAXL 50 // Log2(maxn) - 50 should do the trick

vector<int> adj[MAXN]; // Adj vector
int parent[MAXN];
int lvl[MAXN];
int anc[MAXN][MAXL]; // DP for lca

/*
	anc[i][j] == (2^j)-th ancestor of i
	anc[i][0] == parent[i]
	anc[i][j] == anc[anc[i][j-1]][j-1]
*/

void dfs(int u){

	for (auto v : adj[u]){

		if (lvl[v] != -1) continue;

		parent[v] = u; // Setting parent
		lvl[v] = lvl[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v){

	// Return vextex that is lca of U and V

	if (lvl[u] < lvl[v]) swap(u, v);

	// Make lvl of U gets equal the lvl of V
	for (int i = MAXL-1; i >= 0; i--)
		if (lvl[u] - (1 << i) >= lvl[v])
			u = anc[u][i];

	if (u == v) return v;

	// We go up as maximum as possible without them
	// beeing equal
	for (int i = MAXL-1; i >= 0; i--)
		if (anc[u][i] != -1 && anc[u][i] != anc[v][i]){
			u = anc[u][i];
			v = anc[v][i];
		}

	return anc[u][0];
}

int main(){

	// Inicitialize lvl array
	for(int i = 0; i < MAXN; i++)
		lvl[i] = -1;

	int root = 1; // TO BE DEFINED
	lvl[root] = 0;
	parent[root] = -1;

	dfs(root);

	// Initializing DP matrix
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXL; j++)
			anc[i][j] = -1;
	
	int N; // Actual number of vertices - TO BE DEFINED
	// Defining parents
	for (int i = 1; i <= N; i++)
		anc[i][0] = parent[i];

	// Calculating DP
	for (int j = 1; j < MAXL; j++)
		for (int i = 1; i <= N; i++)
			if (anc[i][j-1] != -1)
				anc[i][j] = anc[anc[i][j-1]][j-1];

	// Calling it
	int ans = lca(u, v);

}