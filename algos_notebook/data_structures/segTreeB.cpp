// SEGMENT TREE - BASIC IMPLEMENTATION
// HERE MAKES SUM QUERIES AND Ai = Ai%X, ie[l,r] QUERIES

#define maxn 112345

struct SegTree {

    ll sum[maxn*4], max_val[maxn*4];
    int n, m;

    // set A[idx] to val
    void update(int node, int i, int j, int idx, ll val){
        if (i == j) {
            sum[node] = val;
            max_val[node] = val;
            return;
        }
        int l = 2*node, r = l+1, mid = (i+j)/2;

        if (idx <= mid) update(l, i, mid, idx, val);
        else            update(r, mid+1, j, idx, val);
        sum[node] = sum[r] + sum[l];
        max_val[node] = max(max_val[r], max_val[l]);
    }

    // Ai = Ai%X, i in [a,b] QUERIES
    void update_mod(int node, int i, int j, int a, int b, ll x){
        if (i > b || a > j || max_val[node] < x) return;
        if (i == j) {
            sum[node] = max_val[node] = sum[node]%x;
            return;
        }
        int l = 2*node, r = l+1, mid = (i+j)/2;
        update_mod(l, i, mid, a, b, x);
        update_mod(r, mid+1, j, a, b, x);
        sum[node] = sum[r] + sum[l];
        max_val[node] = max(max_val[r], max_val[l]);
    }
    
    // query sum in [a,b]
    ll query_sum(int node, int i, int j, int a, int b){
        if (a <= i && j <= b) return sum[node];
        if (i > b || a > j) return 0ll;
        int l = 2*node, r = l+1, mid = (i+j)/2;
        ll ansl = query_sum(l, i, mid, a, b);
        ll ansr = query_sum(r, mid+1, j, a, b);
        return ansl + ansr;
    }
};

// query_sum(1, 0, n-1, l, r));
// update_mod(1, 0, n-1, l, r, x);
// update(1, 0, n-1, k, x);
