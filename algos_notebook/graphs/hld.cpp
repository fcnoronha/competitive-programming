// HEAVY LIGHT DECOMPOSITION

vector<int> prt, lvl, heavy, head, pos;
int clk;

int dfs_hld(int u) {
    int sz = 1, mx_sz = 0;
    for (int v: adj[u]) {
        if (v == prt[u]) continue;
        prt[v] = u;
        lvl[v] = lvl[u] + 1;
        int c_sz = dfs_hld(v);
        sz += c_sz;
        if (mx_sz < c_sz)
            mx_sz = c_sz, heavy[u] = v;
    }
    return sz;
}

void decompose_hld(int u, int h) {
    head[u] = h, pos[u] = clk++;
    if (heavy[u] != -1)
        decompose_hld(heavy[u], h);
    for (int v: adj[u]) 
        if (v != prt[u] && v != heavy[u])
            decompose_hld(v, v);
}

// it is better to let the nodes in the tree be 0 indexed
void init_hld(int root, int n) {
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    prt = vector<int>(n);
    lvl = vector<int>(n);
    pos = vector<int>(n);
    clk = 0;
    dfs_hld(root);
    decompose_hld(root, root);
}

// query for the maximum element in a path
int query_hld(int a, int b) {
    int ans = 0, path_max;
    while (head[a] != head[b]) {
        if (lvl[head[a]] > lvl[head[b]]) swap(a, b);
        path_max = segment_tree_query(pos[head[b]], pos[b]); // CHANGE
        ans = max(ans, path_max);
        b = prt[head[b]];
    }
    if (lvl[a] > lvl[b]) swap(a, b);
    path_max = segment_tree_query(pos[a], pos[b]); // if its edge make pos[a]+1
    ans = max(ans, path_max);
    return ans;
}