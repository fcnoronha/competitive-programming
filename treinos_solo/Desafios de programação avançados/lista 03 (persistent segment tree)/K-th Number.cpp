#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 112345
#define NEUTRAL INT_MAX

struct PSTree { 
    
    // persistent segment tree for min over integers
    // queries of type [s, e)
	
    // segment tree, left childs, right childs
    vector<int> st, L, R;
    int n, rt, cnt;
	
    PSTree(int _n): st(1,NEUTRAL), L(1,0), R(1,0), n(_n), rt(0), cnt(0) {}
	
    int new_node(int v, int l=0, int r=0) {

		int ks = st.size();
		st.push_back(v);
        L.push_back(l);
        R.push_back(r);
		return ks;
	}

    int init(int s, int e) { // not necessary in most cases
		
        if (s+1 == e) return new_node(0);
		
        int m = (s+e)/2, l = init(s,m), r = init(m,e);
		return new_node(min(st[l],st[r]), l, r);
    }

	int upd(int k, int s, int e, int p, int v) {
		
        int ks = new_node(st[k], L[k], R[k]);
        if (s+1 == e) {
            st[ks] = 1;
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
		
        st[ks] = st[L[ks]] + st[R[ks]];
		return ks;
	}

	int query(int k1, int k2, int s, int e, int k) {

        if (s+1 == e) {
            return s;
        }
		
        int m = (s+e)/2;
        int delta = st[L[k2]] - st[L[k1]];

        if (delta >= k) return query(L[k1], L[k2], s, m, k);

 		return query(R[k1], R[k2], m, e, k-delta);
	}

	int upd(int k, int p, int v) { return rt=upd(k,0,n,p,v); }
	int upd(int p) { return upd(rt,p,0); } // update on last root
	int query(int k1, int k2, int k) { return query(k1,k2,0,n,k); };
}; 

map<int, int> mp, rmp;
int a[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m;
    cin >> n >> m;

    PSTree seg(n);

    fr(i, n) {
        cin >> a[i];
        mp[a[i]] = 0;
    }

    int clk = 0;
    for (auto &x: mp) {
        rmp[clk] = x.f;
        x.s = clk++;
    }

    vi roots;
    int aux = seg.init(0, n);
    seg.rt = aux;
    roots.pb(aux);

    fr(i, n) {
        roots.pb(seg.upd(mp[a[i]]));
    }

    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;

        int idx = seg.query(roots[i-1], roots[j], k);
        p(rmp[idx]);
    }
}
