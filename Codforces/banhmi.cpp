// http://codeforces.com/contest/1062/problem/C

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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll mod = 1e9+7;

ll nu[100008], n, q;
string trouxa;

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

int main(){
	cin >> n >> q;
	cin >> trouxa;

	frr(i, n){		
		nu[i] += nu[i-1];
		if (trouxa[i-1] == '1')
			nu[i]++;	
	}

	ll l, r;
	fr(i, q){
		cin >> l >> r;
		ll n = nu[r] - nu[l-1];
		ll nz = (r-l+1) - n;

		n = fastexp(2, n) - 1;		
		nz = fastexp(2, nz)	;

		ll ans = (nz*n)%mod;

		cout << ans << endl;
	}
}
