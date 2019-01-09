//codeforces.com/contest/1077/problem/A

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

int main(){
	fastio

	ll t;
	cin >> t;

	while (t--){
		ll a, b, k;
		cin >> a >> b >> k;

		ll aux = a-b, ans;
		aux = ceil(k/2.0);
		ans = aux*a;
		aux = floor(k/2.0);
		ans -= aux*b;

		cout << ans << endl; 
	}
		
}
