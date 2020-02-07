// BELLMAN-FORD - SHORTEST PATH WITH NEGATIVE EDGES
// O(v*e) - #vertices * #edges

struct edge{
	int u, v, w;
} e[1001]; // TO BE SET 

int dist[1001]; // TO BE SET

void bf(int root, int nv, int ne){

	for (int i = 0; i < nv; i++)
		dist[i] = INT_MAX;
	
	dist[root] = 0;
	for (int i = 1; i < nv; i++){
		for (int j = 0; j < ne; j++){
			int u = e[j].u;
			int v = e[j].v;
			int w = e[j].w;
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