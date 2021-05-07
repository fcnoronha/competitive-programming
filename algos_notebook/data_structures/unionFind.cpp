
// WEIGHTED QUICK UNION

struct UnionFind {
    vector<int> id, sz;

    UnionFind(int _maxn): id(_maxn), sz(_maxn) {
        for (int i = 0; i < _maxn; i++)
            id[i] = i, sz[i] = 1;
    }

    int find(int p) {
        if (id[p] == p) return p;
        return id[p] = find(id[p]); 
    }

    void uni(int p, int q) {
        p = find(p); q = find(q);
        if (p == q) return;
        if (sz[p] > sz[q]) swap(p, q);
        id[p] = q;
        sz[q] += sz[p];
    }
};
