//www.spoj.com/problems/MKTHNUM/

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

int a[maxn], rmp[maxn];

struct node {
	int count;
	node *left, *right;

	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}

	node* insert(int l, int r, int w);
};

node *root[maxn];
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

int query(node *a, node *b, int l, int r, int k) {

    if(l+1 == r)
		return l;

	int m = (l+r)/2;
	int count = a->left->count - b->left->count;
	if(count >= k)
		return query(a->left, b->left, l, m, k);

	return query(a->right, b->right, m, r, k-count);
}

int main() {
    fastio

	int n, m;
	cin >> n >> m;

	map<int, int> mp;
	fr(i, n) {
		cin >> a[i];
		mp[a[i]] = 0;
	}

	int cnt = 0;
	for (auto &x : mp) {
        rmp[cnt] = x.f;
		x.s = cnt++;
	}

	null->left = null->right = null;
	fr(i, n) {
        if (i == 0)
            root[i] = null->insert(0, cnt, mp[a[i]]);
        else
            root[i] = root[i-1]->insert(0, cnt, mp[a[i]]);
    }

    int u, v, k;
	while(m--) {
		cin >> u >> v >> k;
		u--; v--;

		int ans = query(root[v], (u==0?null:root[u-1]), 0, cnt, k);
		p(rmp[ans]);
	}
}
