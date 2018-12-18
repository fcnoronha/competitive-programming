// https://codeforces.com/contest/1081/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll mod = 998244353;

ll fastexp(ll base, ll exp){
	ll ans = 1ll;
	while(exp){
		if(exp%2ll) {
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		exp /= 2ll;
	}
	return ans;
}

ll fac(ll x){
	if (x == 0) return 1ll;
	return x*fac(x-1)%mod;
}

int main(){
	ll n, m, k;
	cin >> n >> m >> k;

	ll ans = fac(n-1);
	ll aux = (fac(k)*fac(n-1-k))%mod;
	aux = fastexp(aux, mod-2);

	ans = (ans*aux)%mod;

	ans = (ans*m)%mod; 	
	ans = (ans*fastexp(m-1, k))%mod;

	cout << ans << endl;
}
