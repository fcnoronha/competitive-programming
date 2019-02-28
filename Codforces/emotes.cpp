//codeforces.com/contest/1117/problem/B

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
	
	ll n, m, k;
	cin >> n >> m >> k;

	ll a[n];
	fr(i, n) cin >> a[i];

	sort(a, a+n);

	ll m1 = a[n-1], m2 = a[n-2];

	if (k >= m){
		cout << m1*m << endl;
		return 0;
	}

	ll ans;
	ans = (m1*k + m2)*(m/(k+1));
	m %= (k+1);
	ans += m1*m;

	cout << ans << endl;
}
