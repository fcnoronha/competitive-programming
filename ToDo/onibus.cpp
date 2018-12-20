// https://www.urionlinejudge.com.br/judge/pt/problems/view/1474

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

const ll mod = 10000000;

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

int main(){
	ll n, k, l;
	while (cin >> n && n != EOF){
		cin >> k >> l;

		ll aux = (k*k)%mod;
		aux += l;
		aux %= mod;
		ll ans = fastexp(aux, n/10);
		if (n%10 != 0) ans = (ans*k)%mod;

		ll aux2 = fastexp(l, (n-5)/10);
		aux2 = (aux2*k)%mod;
		if ((n-5)%10 != 0) aux2 = (aux2*k)%mod;

		ans = (ans + aux2)%mod;

		cout << ans << endl;
	}
}
