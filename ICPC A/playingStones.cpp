// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4228

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

ll g(ll n){
	if (n == 0 || n == 1) return 0;

	if ((n%2) == 0)
		return n/2ll;
	
	return g(n/2ll);
}

int main(){
	fastio
	
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		ll ans = 0ll;
		while (n--){
			ll aux;
			cin >> aux;

			ans ^= g(aux);
		} 

		if (ans) p(YES);
		else p(NO);
	}
}
