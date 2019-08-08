// https://www.codechef.com/problems/CKISSHUG

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

const int mod = 1000000007;

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

int main(){
	ll t; cin >> t;
	while (t--){
		ll n, aux1, aux2, ans;
		cin >> n;
		aux1 = ceil((n+1)/2.0);
		aux2 = floor((n+1)/2.0);

		ans = fastexp(2, aux1) + fastexp(2, aux2) - 2ll;
		ans %= mod;

		cout << ans << endl;
	}
}
