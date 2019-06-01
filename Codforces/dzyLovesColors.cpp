// codeforces.com/contest/444/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

#define maxn 100010*5

ll n, m;
ll mn[maxn], mx[maxn], sum[maxn];
ll lazy_x[maxn], lazy_inc[maxn]; /* For lazy seg tree */

void unlazy (ll i, ll l, ll r) {

	if (!lazy_x[i]) return;

	/* Increasing whole interval */
	sum[i] += lazy_inc[i] * (r-l+1ll);
	mn[i] = mx[i] = lazy_x[i];

	/* "Lazying" */
	if (l != r) {
		lazy_x[i*2] = lazy_x[i*2+1] = lazy_x[i];
		lazy_inc[i*2] += lazy_inc[i];
		lazy_inc[i*2+1] += lazy_inc[i];
	}

	lazy_x[i] = lazy_inc[i] = 0ll;
}

void build (ll i, ll l, ll r) {

	/* Leaf nodes */
	if (l == r) {
		mn[i] = mx[i] = r;
		return;
	}

	ll m = (l+r)/2;
	build(2*i, l, m);
	build(2*i + 1, m+1, r);

	/* Building myself with child segments */
	mn[i] = min(mn[2*i], mn[2*i + 1]);
	mx[i] = max(mx[2*i], mx[2*i + 1]);
	sum[i] = sum[2*i] + sum[2*i + 1];
}

void update (ll i, ll l, ll r, ll ql, ll qr, ll x) {

	unlazy(i, l, r);

	if (l > qr || r < ql) return;

	/* Intern segment with equal values */
	if (l >= ql && qr >= r && mn[i] == mx[i]) {
		lazy_x[i] = x;
		lazy_inc[i] = abs(x - mx[i]);
		unlazy(i, l, r);
		return;
	}

	/* Go for childs */
	ll m = (l+r)/2;
	update(i*2, l, m, ql, qr, x);
	update(i*2 + 1, m+1, r, ql, qr, x);

	/* Building myself with child segments */
	mn[i] = min(mn[2*i], mn[2*i + 1]);
	mx[i] = max(mx[2*i], mx[2*i + 1]);
	sum[i] = sum[2*i] + sum[2*i + 1];
}

ll get(ll i, ll l, ll r, ll ql, ll qr) {
	unlazy(i, l, r);
	if (l > qr || ql > r) return 0ll;

	if (l >= ql && qr >= r) return sum[i];

	ll m = (l+r)/2;
	return get(2*i, l, m, ql, qr) + get(2*i + 1, m+1, r, ql, qr);
}

int main(){
	fastio

	cin >> n >> m;

	build(1, 1, n);

	ll op, l, r, x;
	while (m--) {

		cin >> op;

		if (op == 1ll) {

			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}

		else {

			cin >> l >> r;
			cout << get(1, 1, n, l , r) << endl;
		}
	}
}
