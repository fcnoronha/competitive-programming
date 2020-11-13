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

#define maxn 21234
vector<pll> adj[maxn];

//////////////////////////////////////////////////////////////////////
// UF

ll id[maxn], sz[maxn];

ll find(ll p) {
    if (id[p] == p) return p;
    return id[p] = find(id[p]); 
}

void uni(ll p, ll q) {
	p = find(p); q = find(q);
	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);
	id[p] = q;
	sz[q] += sz[p];
}

void initialize(ll n) {
    for (ll i = 0; i <= n; i++)
		id[i] = i, sz[i] = 1;
}

////////////////////////////////////////////////////////////////
// SEG

ll seg[maxn*2], lzy[maxn];
ll nseg; // array size
ll hseg; // seg heigth

// just to apply_seg changes in one node
void apply_seg(ll p, ll val) {
	seg[p] += val;
	if (p < nseg) 
		lzy[p] += val;
}
 
// update all the parents of a given node
void build(ll p) {
	while (p > 1) { 
		p >>= 1;
		seg[p] = min(seg[p<<1], seg[p<<1|1]) + lzy[p];
	}
}
 
// propagates changes from all the parents of a node, down the tree
void push(ll p) {
	for (ll sss = hseg; sss > 0; --sss) {
		ll i = (p>>sss);
		if (lzy[i]) {
            ll ii = (i<<1);
			apply_seg(ii, lzy[i]);
			apply_seg(ii, lzy[i]);
			lzy[i] = 0;
		}
	}
}
 
// add val to [l, r)
void update(ll l, ll r, ll val) {
	l += nseg, r += nseg;
	ll l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply_seg(l++, val);
		if (r&1) apply_seg(--r, val);
	}
	build(l0);
	build(r0 - 1);
}
 
// query [l, r), 0-indexed
ll query_seg(ll l, ll r) {
	l += nseg, r += nseg;
	push(l);
	push(r - 1);
	ll ans = INF;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) ans = min(ans, seg[l++]);
		if (r&1) ans = min(seg[--r], ans);
	}
	return ans;
}
 
/////////////////////////////////////////////////////////////////////////
// HLD
 
ll prt[maxn], lvl[maxn], heavy[maxn], head[maxn], pos[maxn], val[maxn];
ll cur_pos;
 
ll dfs(ll u) {
    ll szaaa = 1, mx_sz = 0;
    for (auto e: adj[u]) {
        ll v = e.f, w = e.s;
        if (v == prt[u]) continue;
        val[v] = w;
        prt[v] = u;
        lvl[v] = lvl[u] + 1;
        ll c_sz = dfs(v);
        szaaa += c_sz;
        if (mx_sz < c_sz)
            mx_sz = c_sz, heavy[u] = v;
    }
    return szaaa;
}
 
void decompose(ll v, ll h) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    for (pii x: adj[v]) 
        if (x.f != prt[v] && x.f != heavy[v])
            decompose(x.f, x.f);
}
 
// it is better to let the nodes in the tree be 0 indexed
void init(ll root, ll n) {
    fr(i, n) {
        heavy[i] = -1;
        head[i] = 0;
        prt[i] = 0;
        lvl[i] = 0;
        pos[i] = 0;
    }
    fr(i, n+n+10) seg[i]=0;
    cur_pos = 0;
    dfs(root);
    decompose(root, root);
}
 
// query for the maximum element in a path
ll query_hld(ll a, ll b) {
    ll res = INF, path_max;
    while (head[a] != head[b]) {
        if (lvl[head[a]] > lvl[head[b]]) swap(a, b);
        path_max = query_seg(pos[head[b]], pos[b]+1); // CHANGE
        res = min(res, path_max);
        b = prt[head[b]];
    }
    if (lvl[a] > lvl[b]) swap(a, b);
    path_max = query_seg(pos[a]+1, pos[b]+1);
    res = min(res, path_max);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    ll n, m, s;
    cin >> n >> m >> s;

    hseg = 32 - __builtin_clz(n);
    nseg = n;

    vector< pair<ll, pii> > edg; 
    fr(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edg.pb({-w, {u,v}});
    }
    sort(all(edg));

    // max spanning tree
    initialize(n);
    for (auto x: edg) {
        ll w = -x.f, u = x.s.f, v = x.s.s;
        if (find(u) == find(v)) continue;
        uni(u, v);
        adj[v].pb({u, w});
        adj[u].pb({v, w});
    }

    init(0, n);
    fr(i, n) update(pos[i], pos[i]+1, val[i]);

    while (s--) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        p(query_hld(u, v));
    }
}
