// KRUSKAL - MST
// O(n*logn + n)

#define maxn 50500 // vertices
#define maxm 200200 // edges

struct Kruskal {

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
};

int main(){    
    cin >> n >> m;
    
    Kruskal K;
    for (int i = 0; i < m; i++)
        cin >> k.edg[i].u >> k.edg[i].v >> k.edg[i].dis;
        
    // 0-indexed, change if graph is not 0 idexed
    for (int i = 0; i < n; i++) k.id[i] = i, k.sz[i] = 1;
    sort(k.edg, k.edg+m, k.comp);
    
    int mst_sz = 0;
    for (int i = 0; i < m; i++){
        if (k.find(edg[i].u) == k.find(edg[i].v)) continue;
        k.uni(k.edg[i].u, k.edg[i].v);           
        k.mst[mst_sz++] = k.edg[i];
    }

    for(int i = 0; i < mst_sz; i++) 	
    	cout << k.mst[i].u << " " << k.mst[i].v << " " << k.mst[i].dis << endl;
}