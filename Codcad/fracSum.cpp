// codcad.com/problem/79

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

ll gcd(ll a, ll b){
  return (b == 0 ? a : gcd(b, a%b));
}

ll gcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main(){
	fastio
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll nb = gcm(b, d);
	a = (nb/b)*a;
	c = (nb/d)*c;

	a += c;

	ll div = gcd(a, nb); 
	a /= div;
	nb /= div;

	cout << a << " " << nb << endl;
}
