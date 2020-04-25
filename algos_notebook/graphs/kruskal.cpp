// KRUSKAL - MST
// O(n*logn + n)

#define maxn 50500 // vertices
#define maxm 200200 // edges

typedef struct edge {
    int dis;
    int u, v;
} t_edge;

bool comp(t_edge a, t_edge b){ 
	return a.dis < b.dis; 
}

int n, m; 
int id[maxn], sz[maxn];
t_edge edg[maxm], mst[maxm];

int find(int p){
    if (id[p] == p) return p;
    return id[p] = find(id[p]); 
}

void uni(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}

int main(){    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
        cin >> edg[i].u >> edg[i].v >> edg[i].dis;
        
    // 0-indexed, change if graph is not 0 idexed
    for (int i = 0; i < n; i++) id[i] = i, sz[i] = 1;
    sort(edg, edg+m, comp);
    
    int mst_sz = 0;
    for (int i = 0; i < m; i++){
        if (find(edg[i].u) == find(edg[i].v)) continue;
        uni(edg[i].u, edg[i].v);           
        mst[mst_sz++] = edg[i];
    }

    for(int i = 0; i < mst_sz; i++) 	
    	cout << mst[i].u << " " << mst[i].v << " " << mst[i].dis << endl;
}