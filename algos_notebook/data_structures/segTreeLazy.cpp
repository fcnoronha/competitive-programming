// SEGTREE - LAZY PROPAGATION
// Reference code - Range update and range querie for max

#define maxn 100000
int seg[maxn * 2], lzy[maxn];
int n; // array size
int h; // seg heigth


// just to apply changes in one node
void apply(int p, int val) {
	seg[p] += val;
	if (p < n) 
		lzy[p] += val;
}

// update all the parents of a given node
void build(int p) {
	while (p > 1) { 
		p >>= 1;
		seg[p] = max(seg[p<<1], seg[p<<1|1]) + lzy[p];
	}
}

// propagates changes from all the parents of a node, down the tree
void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (lzy[i]) {
			apply(i<<1, lzy[i]);
			apply(i<<1|1, lzy[i]);
			lzy[i] = 0;
		}
	}
}

// add val to [l, r)
void update(int l, int r, int val) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, val);
		if (r&1) apply(--r, val);
	}
	build(l0);
	build(r0 - 1);
}

// query [l, r), 0-indexed
int query(int l, int r) {
	l += n, r += n;
	push(l);
	push(r - 1);
	int ans = -INF;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) ans = max(ans, seg[l++]);
		if (r&1) ans = max(seg[--r], ans);
	}
	return ans;
}

int main() {
	cin >> n;
	h = 32 - __builtin_clz(n);
	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		update(i, i+1, val);
	}
}
