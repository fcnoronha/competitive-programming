#include "bits/stdc++.h"
using namespace std;

#define NEUTRAL INT_MAX

struct PSTree { 
    // queries of type [s, e)
    // persistent segment tree for min over integers
    // segment tree, left childs, right childs
    vector<int> st, L, R;
    int n, rt;
	
    PSTree(int _n): st(1,NEUTRAL), L(1,0), R(1,0), n(_n), rt(0) {}
	
    int new_node(int v, int l=0, int r=0) {
		int ks = st.size();
		st.push_back(v);
        L.push_back(l);
        R.push_back(r);
		return ks;
	}

	int init(int s, int e, int *a) {
        if (s+1 == e) return new_node(a[s]);
        int m = (s+e)/2, l = init(s, m, a), r = init(m, e, a);
		return new_node(min(st[l], st[r]), l, r);
	}

	int upd(int k, int s, int e, int p, int v) {
        int ks = new_node(st[k], L[k], R[k]);
        if (s+1 == e) {
            st[ks] = v;
            return ks;
        }
		int m = (s+e)/2, ps;
        if (p < m) { 
            ps = upd(L[ks], s, m, p, v);
            L[ks] = ps;
        }
		else {
            ps = upd(R[ks], m, e, p, v);
            R[ks] = ps;
        }
        st[ks] = min(st[L[ks]], st[R[ks]]);
		return ks;
	}

	int query(int k, int s, int e, int a, int b) {
		if (e <= a || b <= s) return NEUTRAL;
		if (a <= s && e <= b) return st[k];
        int m = (s+e)/2;
		return min(query(L[k], s, m, a, b), query(R[k], m, e, a, b));
	}

	int query(int k,int a, int b) { return query(k, 0, n, a, b); }
	int upd(int k, int p, int v) { return rt = upd(k, 0, n, p, v); }
	int upd(int p, int v) { return upd(rt, p, v); } // update on last root
	int init(int *a) { return init(0, n, a); }
}; 

// usage: 
//   STree rmq(n);
//   root=rmq.init(x);
//   new_root=rmq.upd(root,i,v);
//   rmq.query(root,s,e);