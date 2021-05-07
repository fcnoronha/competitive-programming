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

#define NEUTRAL 0

struct PSTree { 
    
    // persistent segment tree for min over integers
    // queries of type [s, e)
	
    // segment tree, left childs, right childs
    vector<ll> st;
    vector<ll> L, R;
    ll n, rt;
	
    PSTree(ll _n): st(1,NEUTRAL), L(1,0), R(1,0), n(_n), rt(0) {}
	
    ll new_node(ll v, ll l=0, ll r=0) {

		ll ks = st.size();
		st.push_back(v);
        L.push_back(l);
        R.push_back(r);
		return ks;
	}

	ll init(ll s, ll e, ll *a) { // not necessary in most cases
		
        if (s+1 == e) return new_node(a[s]);
        ll m = (s+e)/2, l = init(s,m,a), r = init(m,e,a);
		return new_node(st[l]+st[r], l, r);
	}

	ll upd(ll k, ll s, ll e, ll p, ll v) {
		
        ll ks = new_node(st[k], L[k], R[k]);
        if (s+1 == e) {
            st[ks] = v;
            return ks;
        }

		ll m = (s+e)/2, ps;
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

	ll query(ll k, ll s, ll e, ll a, ll b) {

		if ( e <= a || b <= s) return NEUTRAL;
		if ( a <= s && e <= b) return st[k];
		
        ll m = (s+e)/2;
		return query(L[k], s, m, a, b)+query(R[k], m, e, a, b);
	}

	ll init(ll *a) { return init(0,n,a); }
	ll upd(ll k, ll p, ll v) { return rt=upd(k,0,n,p,v); }
	ll upd(ll p, ll v) { return upd(rt,p,v); } // update on last root
	ll query(ll k,ll a, ll b) { return query(k,0,n,a,b); };
}; 

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    ll n;
    cin >> n;

    PSTree seg(n);

    ll a[n];
    fr(i, n) cin >> a[i];

    vi roots;
    roots.push_back(seg.init(a));

    ll q; cin >> q;
    while (q--) {

        ll op; cin >> op;

        if (op == 1) {
            ll idx, pos, v;
            cin >> idx >> pos >> v;

            pos--;
            v += seg.query(roots[idx], pos, pos+1);
            roots.pb(seg.upd(roots[idx], 0, n, pos, v));
        }
        else {
            ll idx, l, r;
            cin >> idx >> l >> r;

            p(seg.query(roots[idx], l-1, r));  
        }
    }
}
