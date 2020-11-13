// SEGTREE
// Reference code - Range update and point querie

#define maxn 100000
int seg[maxn * 2];
int n; // array size

void build_seg() {
	for (int i = n-1; i > 0; i--)
		seg[i] = seg[i<<1] + seg[i<<1|1];
}

// update in [l, r), 0-indexed
void update_seg(int l, int r, int val) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) seg[l++] += val;
		if (r&1) seg[--r] += val;
	}
} 

// value at position p
int query_seg(int p) {
	int ans = 0;
	for (p += n; p > 0; p >>= 1) 
		ans += seg[p];
	return ans;
}

// push all modifications to leaves
void push_seg() {
	for (int i = 1; i < n; i++) {
		seg[i<<1] += seg[i];
		seg[i<<1|1] += seg[i];
		seg[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seg[i+n]; // put direct in leaf nodes;
	build_seg();
}