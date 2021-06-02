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


struct STree {

    vector<int> st, lazy;
    int n, NEUTRAL = -1;
    
    STree(int _n): st(4*_n+5, 0), lazy(4*_n+5, -1), n(_n) {}
    
    void init(int k, int s, int e, int *a) { // a is array
        lazy[k] = NEUTRAL; // lazy neutral element
        if (s+1==e) { 
            st[k]=a[s];
            return;
        }
        int m = (s+e)/2;
        init(2*k  , s, m, a);
        init(2*k+1, m, e, a);
        st[k] = st[2*k] + st[2*k+1]; // operation
    }

    void push(int k, int s, int e){
        if (lazy[k] == NEUTRAL) return; // if neutral, nothing to do
        st[k] = (e-s)*lazy[k]; // update st according to lazy
        if (s+1<e) { // propagate to children
            lazy[2*k] = lazy[k];
            lazy[2*k+1] = lazy[k];
        }
        lazy[k] = NEUTRAL; // clear node lazy
    }

    void upd(int k, int s, int e, int a, int b, int v){
        push(k, s, e);
        if (s>=b || e<=a) return;
        if (s>=a && e<=b ){
            lazy[k] = v; // accumulate lazy
            push(k, s, e);return;
        }
        int m = (s+e)/2;
        upd(2*k, s, m, a, b, v);
        upd(2*k+1, m, e, a, b, v);
        st[k] = st[2*k] + st[2*k+1]; // operation
    }

    int query(int k, int s, int e, int a, int b){
        if (s>=b || e<=a) return 0; // operation neutral
        push(k, s, e);
        if (s>=a && e<=b) return st[k];
        int m = (s+e)/2;
        return query(2*k, s, m, a, b) + query(2*k+1, m, e, a, b); // operation
    }

    void init(int *a) { init(1,0,n,a); }
    void upd(int a, int b, int v) { upd(1,0,n,a,b,v); }
    int query(int a, int b) { return query(1,0,n,a,b); }
}; 
// usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int f[26];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, q; cin >> n >> q;

    string s; cin >> s;

    vector<STree> vst(26, STree(n));
    fr(i, n)
        vst[s[i]-'a'].upd(i, i+1, 1);

    while (q--) {

        int l, r, o; cin >> l >> r >> o;
        l--, r--;

        int cur = 0;

        if (o == 1) {
            fr(c, 26) {

                int amt = vst[c].query(l, r+1);
                if (amt == 0) continue;

                vst[c].upd(l, r+1, 0);
                vst[c].upd(l+cur, l+cur+amt, 1);
                cur += amt;

                amt = vst[c].query(l, r+1);
                if (amt == 0) continue;
            }
        }
        else {
            for (int c = 25; c >= 0; c--) {

                int amt = vst[c].query(l, r+1);
                if (amt == 0) continue;

                vst[c].upd(l, r+1, 0);
                vst[c].upd(l+cur, l+cur+amt, 1);
                cur += amt;
            }
        }
    }

    fr(i, n) 
        fr(c, 26) 
            if (vst[c].query(i, i+1))
                s[i] = 'a'+c;
    
    p(s);
}
