// CENTROID DECOMPOSITION
// O(nlgn)
// codeforces.com/blog/entry/58025

#define maxn 100000
vector<int> adj[maxn];
int seen[maxn], sz[maxn];

void get_sz(int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue; 
        get_sz(v, u);
        sz[u] += sz[v];
    }
}

int dfs_centroid(int u, int p, int n) {
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        if (sz[v] > n/2) return dfs_centroid(v, u, n);
    }
    return u;
}

int find_centroid(int r) {
    get_sz(r, r);
    int n = sz[r];
    return dfs_centroid(r, r, n);
}

// generates deomposed tree
void decomposition(int u, int lvl) {
    int c = find_centroid(u);
    seen[c] = 1;
    for (auto v: adj[c]) {
        if (seen[v]) continue;
        decomposition(v, lvl+1);
    }

    // here I have a centroid with depth lvl
    // do my code

    seen[c] = 0;
}

// main
void decompose() {
    // 1 is the root, change accordingly
    decomposition(1, 0);  
}