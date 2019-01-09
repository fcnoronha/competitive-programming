// codeforces.com/contest/1055/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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

int main(){
	fastio
	
	ll n, m, l, ans = 0;
	cin >> n >> m >> l;

	ll val[n+2], valo[n+1];
	frr(i, n) cin >> val[i], valo[i] = val[i];

	frr(i, n) val[i] = val[i] > l;
	val[0] = val[n+1] = 0;

	frr(i, n)
		if (val[i] && val[i-1] == 0) ans++;
	
	// frr(i, n) dbg(val[i]);

	fr(i, m){

		int o;
		cin >> o;

		if (!o) cout << ans << endl;

		else {
			int p, d;
			cin >> p >> d;

			if (val[p]) continue;

			valo[p] += d;
			val[p] = valo[p] > l;

			if (!val[p]) continue;

			if (val[p-1] && val[p+1]) ans--;

			if (!val[p-1] && !val[p+1]) ans++;
		}
	}
}
