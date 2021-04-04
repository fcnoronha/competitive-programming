/*
    LOWEST COMMON ANCESTOR
    O(nlogn) preprocess
    O(logn) query
    1-indexed
*/

#define maxn 1000
#define maxl 25 // ceil(log2(n))

struct Lca {

    int timer;
    int tin[maxn], tout[maxn], up[maxn][maxl];
    vi adj[maxn]; // graph rep

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < maxl; ++i)
            up[u][i] = up[up[u][i-1]][i-1];

        for (int v: adj[u]) 
            if (v != p)
                dfs(v, u);
        
        tout[u] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = maxl-1; i >= 0; i--) 
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }
};

int main() {

    Lca l;
    l.dfs(root, root); // init
}
