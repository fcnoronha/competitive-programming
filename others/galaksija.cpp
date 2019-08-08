//open.kattis.com/problems/galaksija

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << "\n"

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 100009

struct t_edge {
    ll u, v, z;
};

ll n, cnt, ans, id[maxn], sz[maxn], xr[maxn], vis[maxn];
vector<pll> adj[maxn];
t_edge edge[maxn];
unordered_map<ll, ll> root_xors[maxn]; // xors values with root in i

ll find(ll p){
    if (id[p] == p) return p;
    return id[p] = find(id[p]);
}

void dfs(ll root, ll v) {

    vis[v] = 1;

    // updating answer, NEW POSSIBILITIES
    ans += root_xors[root][ xr[v] ]++;

    for (auto x : adj[v]) {

        ll u = x.f;
        ll z = x.s;

        // updating nodes for connection with root
        if (vis[u]) continue;
        xr[u] = xr[v]^z;

        dfs(root, u);
    }
}

void uni(ll p, ll q, ll z){

    ll op = p, oq = q;

	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q), swap(op, oq);

    // op is the root of smaller subtree
    xr[op] = xr[oq]^z;
    dfs(q, op);
    ms(vis, 0);

    // eliminating old xor's of the answer
    for (auto x : root_xors[p]) {
        ll m = x.s;
        ans -= (m*(m-1ll))/2ll;
    }
    root_xors[p].clear();

	id[p] = q;
	sz[q] += sz[p];
}

int main(){

    /*
    For solving this problem you have to know that:
        1. x^x = 0
        2. x^0 = x.

    How the problem can be solved with this? Take a node X and make it
    the root of the tree, the path of node A to B is equal to the path
    (A-X)^(B-X), try to prove it using the rules above.

    Now you know this, the problem becomes more of a implementation kind,
    but nothing is to dificullt using maps.

    Note that we want to compute the number of paths such that (A-X)^(B-X)
    = 0, that leads to A^X = B^X, so just make the count of pairwise
    posibilities.
    */

    fastio

    cin >> n;

    ll u, v, z;
    fr(i, n-1) {
        cin >> u >> v >> z;
        edge[i] = {--u, --v, z};
    }

    vl order(n-1), ans_v;
    for (auto &x : order) cin >> x, x--;
    fr(i, n)
        id[i] = i, sz[i] = 1, root_xors[i][0]++;

    // reversing for union find
    reverse(all(order));

    ans_v.pb(ans);
    for (auto i : order) {

        u = edge[i].u;
        v = edge[i].v;
        z = edge[i].z;

        uni(u, v, z);

        // adding/creating edges
        adj[u].pb({v, z});
        adj[v].pb({u, z});

        ans_v.pb(ans);
    }

    reverse(all(ans_v));
    pv(ans_v);
}
