// BELLMAN-FORD - SHORTEST PATH WITH NEGATIVE EDGES

// O(v*e) - v = number of vertices and e = number of edges

#include "bits/stdc++.h"
using namespace std;

struct edge{
	int u, v, w;
} e[1001]; // TO BE SET 

int dist[1001]; // TO BE SET

void bf(int root, int nv, int ne){

	// nv = Number of vertices, ne = number of edges

	// Initializing arrays - INDEXED BY 0 
	for (int i = 0; i < nv; i++)
		dist[i] = INT_MAX;
	
	dist[root] = 0;
	
	// Repeat nv-1 times
	for (int i = 1; i < nv; i++){
		// Iterating all edges
		for (int j = 0; j < ne; j++){
			int u = e[j].u;
			int v = e[j].v;
			int w = e[j].w;

			// Updating distances
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	// Checking for cycles
	for (int i = 0; i < ne; i++){
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;

		if (dist[u] != INT_MAX && dist[u] + w < dist[v])
			printf("OLHA O CICLO AQ\n");
	}
}