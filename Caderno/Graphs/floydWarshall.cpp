// FLOYD WARSHALL

/*

	Pretty simple code to find the minimum maximum distance from one vertex
	to any other. "Chose" one vertex, and from it, the maximum distance to 
	any other vertex will be the lowest possible.

	O(n^3)

*/

for(k = 0; k < n; k++) {
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++){
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}

/*

	The code above set the minimum distances. To find the answer, do as follow

*/

long long int ans = LLONG_MAX, aux = -1;

for(i = 0; i < n; i++) {
	for(j = 0; j < n; j++){
		if (i == j) continue;
		aux = max(aux, dist[i][j]);
	}
	ans = min(ans, aux);
	aux = -1;
}
