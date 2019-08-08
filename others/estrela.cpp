// www.urionlinejudge.com.br/judge/en/problems/view/1233

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
	
typedef long double ld;

int main(){
	fastio
	
	ll n, ans;
	while (cin >> n && n != EOF){

		ld aux = (ld(n));
		// Euler Totient
		for (ll p = 2; p*p <= n; p++){

			if (n%p == 0){
				while (n%p == 0) n /= p;
				aux *= (1.0 - (1.0/(ld)p));
			}
		}

		// n is prime
		if (n > 1){
			aux *= (1.0 - (1.0/ld(n)));
		}

		ans = (ll)aux;
		ans = ceil(ans/2.0);

		cout << ans << endl;
	}
}
