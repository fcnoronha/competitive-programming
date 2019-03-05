//codeforces.com/contest/1118/problem/D2

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

#define MAXN 900009

ll a[MAXN];
ll n, m;

bool taoquei(ll i){

	ll cnt = -1, ans = 0;
	for (ll j = 0; j < n; j++){
		cnt += (j%i == 0);
		if (cnt >= a[j]) break;

		ans += a[j] - cnt;
	}

	return (ans >= m);
}

int main(){
	fastio

	cin >> n >> m;

	ll mx = 0;
	fr(i, n) cin >> a[i], mx += a[i];

	ll grg = mx - m;

	if (grg < 0){
		p(-1);
		return 0;
	}

	sort(a, a+n);
	reverse(a, a+n);

	ll l = 1, r = n;
	while (r - l > 1) {

		ll m = (l+r)/2;

		if (taoquei(m)) r = m;
		else l = m;
	}

	if (taoquei(l)) cout << l << endl;
	else cout << r << endl;
}
