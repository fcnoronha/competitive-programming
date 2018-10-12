// Minimum spanning tree. Define um suconjunto de arestas que conectam todos os 
// vertices de um grafo, com peso minimo. O(n*logn + n)

typedef struct aresta{
    int dis;
    int x, y;
}t_aresta;

// Usado na ordenaçao
bool comp(t_aresta a, t_aresta b){ 
	return a.dis < b.dis; 
}

#define MAXN 50500 // vertices
#define MAXM 200200 // arestas

int n, m; 
t_aresta aresta[MAXM];

// para o union find
int id[MAXN];
int sz[MAXN];

// a árvore
t_aresta mst[MAXM];

int find(int x){
    if(id[x] == x) return x;
    return id[x] = find(id[x]);
}

void join(int a, int b){    
    a = find(a);
    b = find(b);
    
    if (sz[a] < sz[b]) id[a] = b;
    else if (sz[b] < sz[a]) id[b] = a;
    else {
        id[a] = b;
        sz[b]++;
    }    
}

int main(){    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
        
    // inicializar os representantes para o union-find
    for (int i = 0; i < n; i++) id[i] = i;
    
    // Ordenar as arestas, menor peso vai ficar em primeiro
    sort(aresta, aresta+m, comp);
    
    int size = 0;
    for(int i = 0; i < m; i++){

        // Se estiverem em componentes distintas, ou seja, ainda nao foram conectadas
        if (find(aresta[i].x) != find(aresta[i].y) ){
            join(aresta[i].x, aresta[i].y);  
            size++;          
            mst[size] = aresta[i];
        }        
    }
    
    // imprimir a MST
    for(int i = 0; i <= n; i++) 	
    	cout << mst[i].x << " " << mst[i].y << " " << mst[i].dis << endl;
}