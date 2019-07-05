//codeforces.com/contest/1180/problem/C

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

int main(){
	fastio

	ll n, q;
	cin >> n >> q;

	deque<ll> dq;
	ll a;

	fr(i, n) {
		cin >> a;
		dq.pb(a);
	}

	pii ans[n+10];
	ll max_index = 0;

	// Getting maximum element
	fr(i, n)
		if (dq[i] > dq[max_index])
			max_index = i;

	ll max_val = dq[max_index];

	// Pre-calculating answers with m < max_index
	frr(i, n) {

		if (dq[0] == max_val)
			break;

		ans[i] = {dq[0], dq[1]};

		if (dq[1] < dq[0]) swap(dq[1], dq[0]);
		dq.pb(dq[0]);
		dq.pop_front();
	}

	ll m;
	// Answering queries
	fr(i, q) {
		cin >> m;

		if (m <= max_index) {
			cout << ans[m].f << " " << ans[m].s << "\n";
			continue;
		}

		ll idx = (m-max_index-1)%(n-1) + 1;
		cout << dq[0] << " " << dq[idx] << "\n";
	}
}
