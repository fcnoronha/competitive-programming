#include<bits/stdc++.h>
using namespace std;

// Cuting vertice - articulation point
// Finds vertices that, if removed with its edges, turn the graph into a disconnected one
// O(E+V)

#define MAXN 10000 // Change according to problem, number of vertices

vector<int> adj[MAXN];  // Graph rep
vector<int> time_in;    // Time when 'i' was discovered first
vector<int> back;       // Discovery time of the lowest predecessor that the i-th vertice is sucessor
vector<int> cut_vertex; // List of found articulation points

int time_spent;

void dfs (int v, int parent){
	back[v] = time_in[v] = ++time_spent; // Initializing

	int children = 0;
	bool isCutVertex = false;

	for (int u : adj[v]){
		int next = u;

		if (next == parent) // Way back
			continue; 

		if (time_in[next] == -1){
			dfs(next, v);

			// if there's a back edge between a descendant of `next` and
    	 	// a predecessor of `v` then `next` will have a lower reachable
      		// vertex than `v`.
			if (back[next] >= time_in[v] && parent != -1)
				isCutVertex = true;

			back[v] = min(back[v], back[next]); // Propagation
			children++;
		}
		else {
			back[v] = min(back[v], time_in[next]);
		}
	}

	// Root
	if (parent == -1 && children > 1)
		isCutVertex = true;

	if (isCutVertex)
		cut_vertex.push_back(v);
}

int main(){
	int n = MAXN; // Receive
	time_spent = 0;
	time_in.assign(n, -1); // Similar to fill
	back.assign(n, -1);

	for (int i = 0; i < n; i++)
		if (time_in[i] == -1)
			dfs(i, -1);

	for (int i : cut_vertex)
		cout << i << endl;

	// If you want to get the lowest value cutting vertex, you need to make a pair with
	// (vertex id, sum of edges values), and get the lowest sum of edges. In order to do
	// this, you only need to iterate through 'adj' vector andd sum all adj[vertex id] components.
}