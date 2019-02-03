//codeforces.com/contest/1111/problem/B

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
typedef long double ld;

int main(){
	fastio
	
	ll n, k, m;
	cin >> n >> k >> m;

	ll a[n], sm = 0ll;
	fr(i, n) cin >> a[i], sm += a[i];

	ll auxn = n, avl = min(m, n*k);
	ld ans = (ld)(sm+avl)/(ld)n;

	sort(a, a+n);
	fr(i, auxn-1){
		n--, m--;

		if (m < 0) break;

		sm -= a[i];
		avl = min(m, n*k);

		ans = max(ans, (ld)(sm+avl)/(ld)n);
	}

	cout << setprecision(6) << fixed << ans << endl;
}
