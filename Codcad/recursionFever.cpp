// codcad.com/problem/75

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

ll memo[1009], a[1009];
ll n, k, m;

void dp(){

	for (int ki = n+1; ki <= k; ki++){

		ll aux = 0;
		frr(i, n)
			aux = ((a[i]*memo[ki - i])%m + aux); 

		memo[ki] = aux%m;
	}

}

int main(){
	fastio
	
	cin >> n >> k >> m;

	frr(i, n) cin >> a[i];
	frr(i, n) cin >> memo[i];

	dp();

	cout << memo[k]%m << endl;
}


