// BFS e DFS

// Exemplo codigo dfs iterativo:

adj[] // representacao do grafo
dist[] // inicializado com infinito
dfs(){
	stack<int> s;
	s.push(origem);
	while(!s.is_empty()){
		v = s.top();
		s.pop();
		for(int u: adj[v]){
			if(dist[u] < infinito) continue;
			s.push(y);
		}
	}
}

// Exemplo codigo BFS:

adj[] // representacao do grafo
dist[] // inicializado com infinito
dfs(){
	queue<int> s;
	s.push(origem);
	while(!s.is_empty()){
		v = s.top();
		s.pop();
		for(int u: adj[v]){  // intera elementos do vector
			if(dist[u] < infinito) continue;  // o continue passa para a proxima iteracao do loop
			s.push(u);
			dist[u] = 1 + dist[v]
		}
	}
}


