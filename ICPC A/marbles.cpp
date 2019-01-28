// uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1031
 
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

ll gcd(ll a, ll b, ll &x, ll &y){

	if (a == 0){
		x = 0;
		y = 1;
		return b;
	}

	ll x1, y1;
	ll d = gcd(b%a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

bool solve(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){

	// Solution will be stored in x0 and y0
	g = gcd(abs(a), abs(b), x0, y0);
	
	if (c%g)
		return false;

	x0 *= c/g;
	y0 *= c/g;
	return true;
}

int main(){
	fastio
	
	ll n, c1, n1, c2, n2;
	while (cin >> n && n){

		cin >> c1 >> n1;
		cin >> c2 >> n2;

		ll g = __gcd(n1, n2);

		if (n%g != 0){

			p(failed);
			continue;
		}

		ll x0, y0;
		solve(n1, n2, n, x0, y0, g);

		n1 /= g;
		n2 /= g;

		ll aux1 = ceil((long double)(-x0)/n2);
		ll aux2 = floor((long double)(y0)/n1);

		if (aux1 > aux2){
			p(failed);
			continue;
		}

		pll ans1 = {(x0 + aux1*(n2)), (y0 - aux1*(n1))};
		pll ans2 = {(x0 + aux2*(n2)), (y0 - aux2*(n1))};

		if ((ans1.f*c1 + ans1.s*c2) > (ans2.f*c1 + ans2.s*c2) && ans2.f >= 0 && ans2.s >=0)
			cout << ans2.f << " " << ans2.s << endl;

		else
			cout << ans1.f << " " << ans1.s << endl;
		
	}
}
