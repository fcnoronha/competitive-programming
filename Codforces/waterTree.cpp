//codeforces.com/contest/343/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 500009

ll seg[maxn<<2], lazy[maxn<<2], prt[maxn], pos_cnt;
pll lmt[maxn];
vi adj[maxn];

void dfs(ll v, ll p) {

    lmt[v].f = ++pos_cnt;

    for (auto u : adj[v]) {
        if (u == p) continue;
        prt[u] = v;
        dfs(u, v);
    }

    lmt[v].s = pos_cnt;
}

void unlazy(ll node, ll i, ll j) {
    if (lazy[node]) {
        seg[node] = (j-i+1);
        if (i != j)
            lazy[2*node] = lazy[1+2*node] = 1ll;
        lazy[node] = 0;
    }
}

void fill(ll node, ll i, ll j, ll a, ll b) {

	ll left = 2*node;
	ll right = 2*node + 1;
	ll mid = (i+j)/2;

    unlazy(node, i, j);
	if (i > j || i > b || a > j) return;

	if (a <= i && j <= b){
		seg[node] = (j-i+1);
		if (i != j)
			lazy[left] = lazy[right] = 1ll;
	}

	else {
		fill(left, i, mid, a, b);
		fill(right, mid+1, j, a, b);
		seg[node] = seg[left] + seg[right];
	}
}

void empty(ll node, ll i, ll j, ll a, ll b) {

	ll left = 2*node;
	ll right = 2*node + 1;
	ll mid = (i+j)/2;

    unlazy(node, i, j);
	if (i > j || i > b || a > j) return;

	if (a <= i && j <= b)
		seg[node] = 0;

	else {
		empty(left, i, mid, a, b);
		empty(right, mid+1, j, a, b);
		seg[node] = seg[left] + seg[right];
	}
}

ll query(ll node, ll i, ll j, ll a, ll b){

	ll left = 2*node;
	ll right = 2*node + 1;
	ll mid = (i+j)/2;

    unlazy(node, i, j);
	if (i > j || i > b || a > j) return 0;

	if (a <= i && j <= b)
		return seg[node];

	else {
		ll sum_l = query(left, i, mid, a, b);
		ll sum_r = query(right, mid+1, j, a, b);
		return sum_r + sum_l;
	}
}

/*
    The problem will be solved with a single segtree. First traverse the
    graph and store pos-order number of each vertex, and also store the
    bounderies of the subtree of i-th vertex.
    The operation to fill will set every node in the range of the subtree
    with 1, the empty operation will set an node to 0.
    For the query you have to check if the vertex is 1 and if none of
    the vertex in its subtree is 0.

    The corner case that got me is the following: if i'm going to fill
    vertex v and some of its children is empty, i have to empty the
    parent of v.
*/

int main(){
    //fastio

    ll n;
    cin >> n;

    ll a, b;
    fr(i, n-1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);

    ll q;
    cin >> q;

    while (q--) {

        ll op, v;
        cin >> op >> v;

        if (op == 1) {
            // fill

            // hehe
            if (query(1, 1, n, lmt[v].f, lmt[v].s) != lmt[v].s-lmt[v].f+1ll) {
                if (v != 1)
                    empty(1, 1, n, lmt[prt[v]].f, lmt[prt[v]].f);
            }

            fill(1, 1, n, lmt[v].f, lmt[v].s);
        }

        else if (op == 2) {
            // empty
            empty(1, 1, n, lmt[v].f, lmt[v].f);
        }

        else {
            // query
            p((query(1, 1, n, lmt[v].f, lmt[v].s) == lmt[v].s-lmt[v].f+1ll));
        }
    }
}
