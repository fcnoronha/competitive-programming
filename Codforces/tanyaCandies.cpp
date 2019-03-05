//codeforces.com/contest/1118/problem/B

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

int main(){
	fastio

	int n;
	cin >> n;

	ll par = 0, impar = 0;
	ll a[n];

	fr(i, n){
		cin >> a[i];

		if ((i+1)%2 == 0) par += a[i];
		else impar += a[i];
	}

	ll ans = 0, aci = 0, acp = 0;
	fr(i, n){

		if ((i+1)%2 == 0){

			ll auxp = acp + (impar - aci);
			acp += a[i];
			ll auxi = aci + (par - acp);

			ans += (auxp == auxi);
		}

		else {

			ll auxi = aci + (par - acp);
			aci += a[i];
			ll auxp = acp + (impar - aci);

			ans += (auxp == auxi);
		}
	}

	cout << ans << endl;
}
