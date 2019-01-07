// codcad.com/problem/189

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

#define MAXN 100009

int bit[100009];

ll query(ll i){
	ll sum = 0;
    for (; i > 0; i -= i&-i)
    	sum += bit[i];
    return sum;
}

void update(ll x, ll i){
	for (; i <= MAXN; i += i&-i)
		bit[i] += x;
}

int main(){
	fastio
	
	ll n;
	cin >> n;

	ll a[n], b[n];

	fr(i, n) cin >> a[i], b[i] = a[i];

	sort(a, a+n);

	ll cnt = 1;
	map<ll, ll> m;
	fr(i,n){
		if (i > 0 && a[i] == a[i-1]) continue;
		m[a[i]] = cnt++;
	}

	fr(i,n){
		b[i] = m[b[i]];
		update(1, b[i]);
		// dbg(b[i]);
	}

	ll ans = 0, i = 0;
	while (i < n-1){

		update(-1, b[i]);

		if ( (query(cnt) - query(b[i]-1) ) > 0){
			// If there's some place higher or equal to act
			ll act = b[i];
			while (act > b[++i]) update(-1, b[i]), ans++;
			continue;
		}

		// Now, we have to find the higher place that is lower to act
		ll act = b[i], hl = b[i];
		while (query(hl) - query(hl-1) == 0) hl--;
		// dbg(hl); dbg(i);

		while (b[++i] < hl) ans++, update(-1, b[i]);
	}

	cout << ans << endl;
}
