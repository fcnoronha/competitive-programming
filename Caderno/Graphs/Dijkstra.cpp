// DIJKSTRA

int n, m, s, t, b, w[1010][1010], visited[10010];
//w: array com pesos das matrizes, visited: array para marcar os pontos ja visitados

int inf = INT_MAX; //definindo uma int com valor "infinito"

vector<int> adj[1010]; //vetor de adjacencias

int main(){
	cin >> n >> m;
	//leitura do grafo
	for(int i = 0; i < m; i++){
		cin >> s >> t >> b;
		w[s][t] = w[t][s] = b; //atribuindo vetor com pesos das arestas
		adj[s].push_back(t); //definindo vetores de ajacencias
		adj[t].push_back(s);
	}

    //definindo vetor com as distancias, com n+2 elementos inicializados com infinito
	vector<int> dist(n+2, inf);

	priority_queue<pair<int,int> > q; //definindo uma lista de prioridades que sera usada para busca
	q.push(make_pair(0, 0)); // O segundo zero representa a raiz do dijkstra, ou seja, pode variar
	dist[0] = 0; //distancia da raiz recebe zero

	while(!q.empty()){ //enquanto a queue nao estiver vazia 
		int v = q.top().second; //v recebe segundo valor da queue, o numero de um no
		q.pop(); //apaga esse ultimo elemento da queue
		if(visited[v] == 1) continue; //caso este no ja tenha sido visitado, segue para a proxima iteracao no while
		visited[v] = 1; //caso contrario, marca o no como visitado e segue com a iteraçao
		for(int u : adj[v]){ //iterando para todos os elementos do vetor de adjacencia do no 'v'
			if(dist[u] > dist[v] + w[v][u]){
				dist[u] = dist[v] + w[v][u]; //atualiza a distancia dql no ate a raiz
				q.push(make_pair(-dist[u], u)); //adiciona elementos a queue
			}
		}
	}

	cout << dist[n+1] << endl;
}

