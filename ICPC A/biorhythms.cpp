// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=697
 
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

const ll mod = 23*28*33;

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

int main(){
	fastio

	ll p, e, i, d, t = 1;
	while (cin >> p >> e >> i >> d && p != -1 && e != -1 && i != -1){

		p %= 23;
		e %= 28;
		i %= 33;

		ll aux1 = mod/23;
		aux1 = aux1*p*fastexp(aux1, 21);
		aux1 %= mod;

		ll aux2 = mod/28;
		aux2 = aux2*e*fastexp(aux2, 11);
		aux2 %= mod;

		ll aux3 = mod/33;
		aux3 = aux3*i*fastexp(aux3, 19);
		aux3 %= mod;

		ll ans = (aux1+aux2+aux3+mod-d)%mod;
		if (ans == 0) ans = mod;

		cout << "Case " << t++ << ": the next triple peak occurs in " << ans << " days." << endl;
		continue;
	}
}
