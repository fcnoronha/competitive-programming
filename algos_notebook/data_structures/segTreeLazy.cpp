// SEGTREE - LAZY PROPAGATION
// Reference code - Range update and range querie for max

#define maxn 100000
int seg[maxn * 2], lzy[maxn];
int n; // array size
int h; // seg heigth


// just to apply changes in one node
void apply_seg(int p, int val) {
	seg[p] += val;
	if (p < n) 
		lzy[p] += val;
}

// update all the parents of a given node
void build_seg(int p) {
	while (p > 1) { 
		p >>= 1;
		seg[p] = max(seg[p<<1], seg[p<<1|1]) + lzy[p];
	}
}

// propagates changes from all the parents of a node, down the tree
void push_seg(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (lzy[i]) {
			apply_seg(i<<1, lzy[i]);
			apply_seg(i<<1|1, lzy[i]);
			lzy[i] = 0;
		}
	}
}

// add val to [l, r)
void update_seg(int l, int r, int val) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply_seg(l++, val);
		if (r&1) apply_seg(--r, val);
	}
	build_seg(l0);
	build_seg(r0 - 1);
}

// query [l, r), 0-indexed
int query_seg(int l, int r) {
	l += n, r += n;
	push_seg(l);
	push_seg(r - 1);
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
		update_seg(i, i+1, val);
	}
}
