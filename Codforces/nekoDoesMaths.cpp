//codeforces.com/contest/1152/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio

	ll a, b;
	cin >> a >> b;

	if (a == b) {
		p(0);
		return 0;
	}

	ll delta = abs(a-b);
	vl divs;
	for (ll i = 1ll; i*i <= delta; i++) {

		if (delta%i) continue;
		divs.pb(i);

		if (i*i != delta)
			divs.pb(delta/i);
	}

	pair<ll, ll> ans = {LLONG_MAX, INT_MAX};
	for (auto d : divs) {
		ll k = (d - a%d) % d;
		pair<ll, ll> anss = {((a+k)*(b+k))/__gcd(a+k, b+k), k};
		ans = min(ans, anss);
	}

	p(ans.s);
}
