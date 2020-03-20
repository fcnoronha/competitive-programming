//codeforces.com/contest/1320/problem/C

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 1123456
#define MAX  1000009

ll seg[maxn*2], lzy[maxn];
int h = 32-__builtin_clz(1000009);

void apply(int p, ll val) {
	seg[p] += val;
	if (p < MAX) 
		lzy[p] += val;
}

void build(int p) {
	while (p > 1) { 
		p >>= 1;
		seg[p] = max(seg[p<<1], seg[p<<1|1]) + lzy[p];
	}
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (lzy[i]) {
			apply((i<<1), lzy[i]);
			apply((i<<1)|1, lzy[i]);
			lzy[i] = 0ll;
		}
	}
}

void update(int l, int r, ll val) {
	l += MAX, r += MAX;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, val);
		if (r&1) apply(--r, val);
	}
	build(l0);
	build(r0 - 1);
}

ll query(int l, int r) {
	l += MAX, r += MAX;
	push(l);
	push(r - 1);
	ll ans = -LINF;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) ans = max(ans, seg[l++]);
		if (r&1) ans = max(seg[--r], ans);
	}
	return ans;
}

int main() {
    fastio;

    ll n, m, p;
    cin >> n >> m >> p;

    vector<pll> wp, am;
    ll x, c, y;
    fr(i, n) {
        cin >> x >> c;
        wp.pb({x, c});
    }
    fr(i, MAX+MAX+10) seg[i] = -LINF;
    fr(i, m) {
        cin >> x >> c;
        am.pb({x, c});
        seg[x+MAX] = max(seg[x+MAX], -c);
    }
    for (int i = MAX-1; i > 0; i--)
        seg[i] = max(seg[i<<1], seg[(i<<1)|1]);

    sort(all(wp));
    sort(all(am));
    ll mxat = 0, mxdf = 0;
    fr(i, n) mxat = max(mxat, wp[i].f);
    fr(i, m) mxdf = max(mxdf, am[i].f);

    vector<pair<pll, ll>> mst;
    fr(i, p) {
        cin >> x >> y >> c;
        //if (x >= mxat || y >= mxdf) continue;
        mst.pb({{x, y}, c});
    }
    sort(all(mst));

    int im = 0;
    ll ans = LLONG_MIN;
    for (auto w: wp) {

        ll at = w.f;
        ll csa = w.s;
        while (im < mst.size() && mst[im].f.f < at) {
            update(mst[im].f.s+1, MAX, mst[im].s);
            im++;
        }

        ans = max(ans, query(1, MAX) - csa);
    }

    p(ans);
}
