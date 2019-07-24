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

#define MAXN 1009

set <ll> st;
ll t[MAXN], dv[MAXN], x[MAXN]; // d == ac


int main(){


	ll m, n;
	cin >> m >> n;

	fr(i, m)
		cin >> t[i];

	fr(i, n)
		cin >> dv[i];


	fr(j, n-m+1){

		int id = 0;
		bool oi = true;
		for (int i = j; i < j+m-2; i++, id++){

			ll a = t[id+1] - t[id];
			ll b = dv[i+1] - dv[i];

			ll c = t[id+2] - t[id+1];
			ll d = dv[i+2] - dv[i+1];

			ll g = __gcd(a, b);
			a /= g; b /= g;

			g = __gcd(c, d);
			c /= g; d /= g;

			if (c != a || d != b){
				oi = 0;
				break;
			}
		}

		if (oi)
			st.insert(dv[j+1] - dv[j]);

	}


	printf("%lu\n", st.size());
	for (auto u : st)
		printf("%lld ", u);
	puts("");
}
