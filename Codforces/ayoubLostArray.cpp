// codeforces.com/contest/1105/problem/C

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

int main(){
	fastio
	
	ll n0, n1, n2;
	ll n, r, l;
	cin >> n >> l >> r;

	/*
	int aux = 0;
	for (int i = l; i <= r; i++) aux += (i%3 == 0);
	n0 = aux;
	aux = 0;
	for (int i = l; i <= r; i++) aux += (i%3 == 1);
	n1 = aux;
	aux = 0;
	for (int i = l; i <= r; i++) aux += (i%3 == 2);
	n2 = aux;
	aux = 0;

	dbg(n0);
	dbg(n1);
	dbg(n2);

	*/
	
	n0 = n1 = n2 = 0;

	while (l <= r && l%3 != 0){

		if (l%3 == 1) n1++;
		else n2++; 

		l++;
	}

	while (r >= l && r%3 != 0){

		if (r%3 == 1) n1++;
		else n2++;

		r--;
	}

	n1 += (r-l)/3;
	n2 += (r-l)/3;
	n0 += (r-l)/3;
	n0 += (r%3 == 0 && l%3 == 0);

	ll ans0 = n0, ans1 = n1, ans2 = n2;

	fr(i, n-1){

		ll aux0, aux1, aux2;

		aux0 = (ans0 * n0)%mod;
		aux0 = (aux0 + (ans2*n1)%mod)%mod;
		aux0 = (aux0 + (ans1*n2)%mod)%mod;

		aux1 = (ans1 * n0)%mod;
		aux1 = (aux1 + (ans0*n1)%mod)%mod;
		aux1 = (aux1 + (ans2*n2)%mod)%mod;

		aux2 = (ans2 * n0)%mod;
		aux2 = (aux2 + (ans0*n2)%mod)%mod;
		aux2 = (aux2 + (ans1*n1)%mod)%mod;

		ans0 = aux0;
		ans1 = aux1;
		ans2 = aux2;
	}

	cout << ans0 << endl;
}
