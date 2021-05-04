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

#include "bits/stdc++.h"
using namespace std;

#define NEUTRAL 0
#define maxn 31234

struct PSTree { 
    
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

	int init(int s, int e) { // not necessary in most cases
		
        if (s+1 == e) return new_node(0);
		
        int m = (s+e)/2, l = init(s,m), r = init(m,e);
		return new_node(0, l, r);
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
		
        st[ks] = st[L[ks]]+st[R[ks]];
		return ks;
	}

	int query(int k1, int k2, int s, int e, int a, int b) {

        if (e <= a || b <= s) return NEUTRAL;
		if (a <= s && e <= b) return st[k2] - st[k1];
		
        int m = (s+e)/2;
		return query(L[k1], L[k2], s, m, a, b) + query(R[k1], R[k2], m, e, a, b);
	}

	int init() { return init(0,n); }
	int upd(int k, int p, int v) { return rt=upd(k,0,n,p,v); }
	int upd(int p, int v) { return upd(rt,p,v); } // update on last root
	int query(int k1, int k2,int a, int b) { return query(k1,k2,0,n,a,b); };
}; 

// usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);

int lst_pos[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;


    int n; cin >> n;

    PSTree seg(n);
    map<int, int> mp;
    vi a(n);
    
    fr(i, n) {
        cin >> a[i];
        mp[a[i]] = 0;
    }

    int clk = 0;
    for (auto &x: mp) {
        x.s = clk++;
    }

    int lst_r;
    vi roots;
    lst_r = seg.init();
    roots.pb(lst_r);

    ms(lst_pos, -1);
    fr(i, n) {
        
        int idx = mp[a[i]];
        if (lst_pos[idx] != -1) 
            lst_r = seg.upd(lst_r, lst_pos[idx], 0);
        
        lst_r = seg.upd(lst_r, i, 1);
        roots.pb(lst_r);
        lst_pos[idx] = i;
    }


    int q; cin >> q;
    while (q--) {

        int l, r;
        cin >> l >> r;

        p(seg.query(roots[l-1], roots[r], l-1, r));
    }
}
