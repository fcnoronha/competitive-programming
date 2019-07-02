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
#define SIEVE_MAX 1000000

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

vl prim;
int primes[100001];

void crivo(){
	for(ll i = 2; i*i <= SIEVE_MAX; i++){
		if(!primes[i]){
			prim.pb(i);
			for(ll j = i*i; j*j <= SIEVE_MAX; j+=i) primes[j] = 1;
		}
	}
}

ll solve(ll x){
	ll ans = x;
	for(auto z: prim){
		if(z*z > x) break;
		if(x%z == 0){
			while(x%z == 0){
				x /= z;
			}
			ans -= ans/z;
		}
	}
	if(x != 1) ans -= ans/x;
	return ans;
}

int main(){
	fastio

	int q;
	cin >> q;
	crivo();
	while (q--) {

		ll n, m;
		cin >> n >> m;

		if (__gcd(n, m) == 1)
			cout << solve(m) << "\n";
		else
			cout << "-1\n";

	}
}
