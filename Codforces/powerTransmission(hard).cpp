//codeforces.com/contest/1163/problem/C2

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

	int n;
	cin >> n;

	pii pos[n];
	fr(i, n) cin >> pos[i].f >> pos[i].s;

	ll cnt = 0ll, ans = 0ll;

	map< pii, set<ll> > coefs;
	fr(i, n) {
		fr(j, n) {

			if (i == j) continue;

			int x1 = pos[i].f, y1 = pos[i].s;
			int x2 = pos[j].f, y2 = pos[j].s;

			// Line coeficientes
			int a = y1 - y2;
			int b = x1 - x2;

			int g = __gcd(a, b);
			a /= g; b /= g;

			if (a < 0 || (!a && b < 0))
				a = -a, b = -b;

			pii slope = {a, b};
			ll c = (ll)(a*x1 - b*y1);
			if (coefs[slope].count(c) == 0) {

				cnt++;
				coefs[slope].insert(c);
				// Intersects with everyone who isnt parallel to it
				ans += cnt - coefs[slope].size();
			}
		}
	}

	p(ans);
}
