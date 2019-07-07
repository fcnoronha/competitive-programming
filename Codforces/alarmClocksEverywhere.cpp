//codeforces.com/contest/1155/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << x << endl
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

	int n, m;
	cin >> n >> m;

	ll x[n], p[m], x0;
	fr(i, n) {
		cin >> x[i];

		if (i == 0)
			x0 = x[0];

		x[n] -= x[0];
	}

	fr(i, m)
		cin >> p[i];

	ll gcd = x[1] - x[0];
	frr(i, n-2)
		gcd = __gcd(gcd, x[i+1] - x[i]);

	fr(i, m)
		if (gcd%p[i] == 0) {
			cout << "YES\n" << x0 << " " << i+1 << "\n";
			return 0;
		}

	p("NO");
}
