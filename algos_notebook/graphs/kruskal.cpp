// KRUSKAL - MST
// O(n*logn + n)

typedef struct edge {
    int dis;
    int u, v;
} t_edge;

bool comp(t_edge a, t_edge b){ 
	return a.dis < b.dis; 
}

#define MAXN 50500 // vertices
#define MAXM 200200 // edges

int n, m; 
t_edge aresta[MAXM], mst[MAXM];
int id[MAXN];
int sz[MAXN];

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
        cin >> aresta[i].u >> aresta[i].v >> aresta[i].dis;
        
    for (int i = 0; i < n; i++) id[i] = i;
    sort(aresta, aresta+m, comp);
    
    int size = 0;
    for(int i = 0; i < m; i++){
        if (find(aresta[i].u) != find(aresta[i].v) ){
            join(aresta[i].u, aresta[i].v);           
            mst[size++] = aresta[i];
        }        
    }

    for(int i = 0; i < size; i++) 	
    	cout << mst[i].u << " " << mst[i].v << " " << mst[i].dis << endl;
}