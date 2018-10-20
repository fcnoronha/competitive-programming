// DIJKSTRA

adj[]  //representaçao do grafo
dist[]  //inicializado com infinito
visited[]  //visitados
w[][]  //pesos dos vertices do grafo

dijkstra(){
	priority_queue<pair<int,int>> q;
	q.insert(0, raiz);
	while(!q.empty()){
		v = q.top().second;
		q.pop();
		if(visited[v]) continue;
		visited[v] = 2;
		for(int u; adj[v]){
			if(dist[u] > dist[v] + w[v][u]){
				dist[u] = dist[v] + w[v][u];
				q.push(-dist[u], u);
			}
		}
	}
}
