#include<bits/stdc++.h>
using namespace std;

// CUT BRIGES: finds the Edges of the graph that, if removed, disconnects the graph.
// O(V+E)

#define MAXN 10000 // Change according to problem, number of vertices

vector<int> adj[MAXN];				  // Graph rep
vector<int> time_in; 				  // Time when 'i' was discovered first
vector<int> back;     				  // Discovery time of the lowest predecessor that the i-th vertice is sucessor
vector< pair<int,int> > cut_edge;     // List of found bridges

int time_spent;

void dfs (int v, int parent){
	back[v] = time_in[v] = ++time_spent; // Initializing

	for (int u : adj[v]){
		int next = u;

		if (next == parent) // Way back
			continue; 

		if (time_in[next] == -1){
			dfs(next, v);

			// if there's a back edge between a descendant of `next` and
    		// a predecessor of `v` then `next` will have a lower back edge discovery time
     	 	// otherwise it's a bridge.
			if (back[next] > time_in[v])
				cut_edge.push_back({v, next});

			back[v] = min(back[v], back[next]); // Propagation
		}
		else {
			back[v] = min(back[v], time_in[next]);
		}
	}
}

int main(){
	int n = MAXN; // Receive
	time_spent = 0;
	time_in.assign(n, -1); // Similar to fill
	back.assign(n, -1);

	for (int i = 0; i < n; i++)
		if (time_in[i] == -1)
			dfs(i, -1);

	for (pair<int,int> i : cut_edge)
		cout << i.first << " " << i.second << endl;

	// If you want to get the lowest value bridge, then you need to iterate through all pairs in the
	// 'cut_edge' array and get the lowest one.
}