// SEGTREE - LAZY PROPAGATION
// Reference code - Range add update and range querie for sum
// Ranges are closed on the end - [a, b)

struct STree {

    int NEUTRAL = 0;
    vector<int> st, lazy;
    int n;
    
    STree(int _n): st(4*_n+5, 0), lazy(4*_n+5, NEUTRAL), n(_n) {}
    
    void init(int k, int s, int e, int *a) { // a is array
        lazy[k] = NEUTRAL; // lazy neutral element
        if (s+1==e) { 
            st[k] = a[s];
            return;
        }
        int m = (s+e)/2;
        init(2*k  , s, m, a);
        init(2*k+1, m, e, a);
        st[k] = st[2*k] + st[2*k+1]; // operation
    }

    void push(int k, int s, int e){
        if (lazy[k] == NEUTRAL) return; // if neutral, nothing to do
        st[k] += (e-s)*lazy[k]; // update st according to lazy
        if (s+1<e) { // propagate to children
            lazy[2*k] += lazy[k];
            lazy[2*k+1] += lazy[k];
        }
        lazy[k] = NEUTRAL; // clear node lazy
    }

    void upd(int k, int s, int e, int a, int b, int v){
        push(k, s, e);
        if (s>=b || e<=a) return;
        if (s>=a && e<=b ){
            lazy[k] += v; // accumulate lazy
            push(k, s, e);return;
        }
        int m = (s+e)/2;
        upd(2*k, s, m, a, b, v);
        upd(2*k+1, m, e, a, b, v);
        st[k] = st[2*k]+st[2*k+1]; // operation
    }

    int query(int k, int s, int e, int a, int b){
        if (s>=b || e<=a) return 0; // operation neutral
        push(k, s, e);
        if (s>=a && e<=b) return st[k];
        int m= (s+e)/2;
        return query(2*k, s, m, a, b) + query(2*k+1, m, e, a, b); // operation
    }

    void init(int *a) { init(1,0,n,a); }
    void upd(int a, int b, int v) { upd(1,0,n,a,b,v); }
    int query(int a, int b) { return query(1,0,n,a,b); }
}; 
// usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);