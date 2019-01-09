//codeforces.com/contest/1077/problem/C

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
	
	int n;
	cin >> n;

	ll sum = 0;
	vector<pll> a(n);
	fr(i, n) cin >> a[i].f, a[i].s = i+1, sum += a[i].f;

	sort(all(a));
	vl ansv;
	int ans = 0;

	sum -= a[n-1].f;

	fr(i, n-1)
		if (sum - a[i].f == a[n-1].f) ans++, ansv.pb(a[i].s);

	if (sum - a[n-2].f == a[n-2].f) ans++, ansv.pb(a[n-1].s);

	cout << ans << endl;
	pv(ansv);
	// pv(a);
}
