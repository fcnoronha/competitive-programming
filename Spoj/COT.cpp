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

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 111111
#define LN 19
int v[maxn], pa[maxn][LN], rmp[maxn], depth[maxn], cnt;
vector<int> adj[maxn];
map<int, int> mp;

struct node {
	int count;
	node *left, *right;

	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}

	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);

node *node::insert(int l, int r, int w) {

    if(l <= w && w < r) {
		if(l+1 == r)
            return new node(this->count+1, null, null);

		int m = (l+r)/2;
		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}

	return this;
}

node *root[maxn];
void dfs(int cur, int prev) {

	pa[cur][0] = prev;
	depth[cur] = (prev == -1 ? 0 : depth[prev] + 1);

	root[cur] = ( prev == -1 ? null : root[prev] )->insert( 0, cnt, mp[v[cur]] );

	for (auto u : adj[cur])
		if (u != prev)
			dfs(u, cur);
}

int LCA(int u, int v) {
	if(depth[u] < depth[v])
		return LCA(v, u);

	int diff = depth[u] - depth[v];

	fr(i, LN)
		if((diff>>i) & 1)
			u = pa[u][i];

	if(u != v)	{
		for (int i = LN-1; i >= 0; i--)
			if(pa[u][i] != pa[v][i]) {
				u = pa[u][i];
				v = pa[v][i];
			}
		u = pa[u][0];
	}

	return u;
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k) {

    if(l+1 == r)
		return l;

	int count = a->left->count + b->left->count - c->left->count - d->left->count;
	int m = (l+r)/2;

    if(count >= k)
		return query(a->left, b->left, c->left, d->left, l, m, k);
	return query(a->right, b->right, c->right, d->right, m, r, k - count);
}

int main() {
    fastio

	int n, m;
	cin >> n >> m;

	fr(i, n) {
		cin >> v[i];
		mp[v[i]];
	}

	for (auto &x : mp) {
		rmp[cnt] = x.f;
        x.s = cnt++;
	}

    int u, v;
	fr(i, n-1) {
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ms(pa, -1);
	null->left = null->right = null;
	dfs(0, -1);

	fr(i, LN-1)
		fr(j, maxn)
			if (pa[j][i] != -1)
				pa[j][i+1] = pa[pa[j][i]][i];

    int k;
	while(m--) {
		cin >> u >> v >> k;;
		u--; v--;

		int lca = LCA(u, v);
        node *root_p;
        if (pa[lca][0] == -1)
            root_p = null;
        else
            root_p = root[pa[lca][0]];

		int ans = query(root[u], root[v], root[lca], root_p, 0, cnt, k);
		p(rmp[ans]);
	}
}
