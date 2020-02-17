/*
    LOWEST COMMON ANCESTOR
    O(nlogn) preprocess
    O(logn) query
    1-indexed
*/

#define maxn 1000
#define maxl 25 // ceil(log2(n))

int timer;
int tin[maxn], tout[maxn], up[maxn][maxl];
vi adj[maxn]; // graph rep

void dfs_lca(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i < maxl; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) 
        if (u != p)
            dfs_lca(u, v);
    
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = maxl-1; i >= 0; --i) 
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int main() {
    dfs_lca(root, root); // init
}
