
// WEIGHTED QUICK UNION

struct UnionFind {

	int id[maxn], sz[maxn];

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

	void init(int n) {
		for (int i = 1; i <= n; i++)
			id[i] = i, sz[i] = 1;
}
};
