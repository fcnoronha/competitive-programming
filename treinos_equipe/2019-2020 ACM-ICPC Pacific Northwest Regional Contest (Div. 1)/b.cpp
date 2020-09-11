#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 2e5 + 1;

int idx[N];

vi adj[N];

struct node{
    int freq, val, i;
    node(){
        freq = val = i = 0;
    }
    node(int aa, int bb, int cc){
        freq=aa, val = bb, i=cc;
    }
    const node operator+(node& a){
        (*this).freq += a.freq;
        return *this;
    }
};

template <class T>
class SegTree{
	public:
	vector<T> seg, lazy, v;
	vi hi, lo;
	function<T(T, T)> upd;
	function<void(vi&, vi&, vector<T>&, vector<T>&, int)> unlzy;
	T LIXO;

	SegTree(int n, T lx, vector<T>& vec, const function<T(T, T)>& updt, 
		const function<void(vi&, vi&, vector<T>&, vector<T>&, int)>& U)
	{
		v = vec, upd = updt, unlzy = U;
		hi.resize(4*n + 1), lo.resize(4*n + 1),	seg.resize(4*n + 1), lazy.resize(4*n + 1);
		LIXO = lx;
		build(1, 0, n-1);
	}

	T build(int nd, int start, int end){
		lo[nd] = start; hi[nd] = end;
		if(start == end){
			return seg[nd] = v[start];
		}
		int mid = (end+start)/2;
		return seg[nd] = upd(build(2*nd, start, mid), build(2*nd + 1, mid + 1, end)); 
	}

	void unlazy(int nd){
		unlzy(hi, lo, seg, lazy, nd);
	}

	T query(int nd, int start, int end){
		unlazy(nd);
		if(hi[nd] < start || lo[nd] > end) return LIXO;
		if(lo[nd] >= start && hi[nd] <= end) return seg[nd];
		return upd(query(2*nd, start, end), query(2*nd + 1, start, end));
	}

	void change(int nd, int start, int end, T x){
		unlazy(nd);
		if(hi[nd] < start || lo[nd] > end) return;
		if(lo[nd] >= start && hi[nd] <= end){
			lazy[nd] + x;
			unlazy(nd);
			return;
		}
		change(2*nd, start, end, x);
		change(2*nd+1, start, end, x);
		seg[nd] = upd(seg[2*nd], seg[2*nd+1]);
	}
};

node update(node a, node b){
    if(a.freq > b.freq) return a;
    if(a.freq == b.freq && a.val < b.val) return a;
    if(a.freq == b.freq && a.val == b.val && a.i < b.i) return a;
    return b;
}

void unlazy(vi& hi, vi& lo, vector<node>& seg, vector<node>& lazy, int cur){
    if(hi[cur] == lo[cur]){
        seg[cur].freq += lazy[cur].freq;
        lazy[cur].freq = 0;
        return;
    }
    seg[cur].freq += lazy[cur].freq;
    lazy[2*cur] + lazy[cur];
    lazy[2*cur + 1] + lazy[cur];
    lazy[cur].freq = 0;
}

int main(){
    int n, k; scanf("%d%d",&n, &k);
    vi vec(n);
    fr(i, n){
        scanf("%d", &vec[i]);
        idx[vec[i]] = i;
        adj[vec[i]].pb(i);
    }
    vector<bool> freq(k+1, false);
    vector<node> vv(n, node(0, 0, 0));
    int cur = 0;
    fr(ii, n){
        int i = n - 1  - ii;
        vv[i].freq = cur - freq[vec[i]];
        vv[i].i = i;
        vv[i].val = vec[i];
        if(freq[vec[i]] == 0) cur++;
        freq[vec[i]] = 1;
    }
    SegTree<node> seg(n, node(-INF, -INF, -INF), vv, update, unlazy);
    int qnt = 0, st = 0;
    vi ans;
    while(qnt < k){
        node nd = seg.query(1, st, n-1);
        ans.pb(nd.val);
        st = nd.i + 1;
        qnt++;
        for(auto p: adj[nd.val]){
            seg.change(1, p, p, node(-INF, 0, 0));
        }
        if(nd.i != idx[nd.val]) seg.change(1, nd.i + 1, idx[nd.val], node(-1, 0, 0));
    }
    vp(ans);
}
