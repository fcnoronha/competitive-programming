//br.spoj.com/problems/DIOFANTO/

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

const ll mod = 1300031;

ll fat(ll x){
	if (x == 0) return 1;
	return x*fat(x-1)%mod;
}

ll fastexp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2) {
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		exp /= 2;
	}
	return ans;
}

ll invmod(ll x){
	return fastexp(x, mod-2);
}

int main(){
	fastio
	
	int t;
	cin >> t;

	while (t--){

		ll n, c;
		cin >> n >> c;

		ll ans = fat(n+c-1);
		ans = (ans*invmod(fat(n-1)))%mod;
		ans = (ans*invmod(fat(c)))%mod;

		cout << ans << endl;

	}
}
