//codeforces.com/problemset/problem/300/C

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

const ll mod = 1e9+7;

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

ll invmod(ll x){
	return fastexp(x, mod-2);
}

int main(){
	fastio
	
	ll fat[1000009];
	fat[0] = 1;
	frr(i, 1000008) fat[i] = (i*fat[i-1])%mod;

	ll a, b, n;
	cin >> a >> b >> n;

	ll ans = 0;
	fr(i, n+1){

		ll aux = a*i + b*(n-i);
		bool da = 1;
		while (aux > 0){
			if (!(aux%10 == a || aux%10 == b)) da = 0;
			aux /= 10;
		}

		if (!da) continue;

		aux = fat[i]*fat[n-i];
		aux %= mod;

		aux = invmod(aux);
		ans = (ans + (aux*fat[n])%mod)%mod;
	}

	cout << ans << endl;
}
