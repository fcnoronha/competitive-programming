// codcad.com/problem/107

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

int main(){
	fastio
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	for (ll i = 0ll; i*i <= c; i++){
		if ((i*a)%b != 0ll && c%(a*i) == 0ll && d%(i*a) != 0ll && (i*a) <= c){
			cout << (i*a) << endl;
			return 0;
		}
	}

	p(-1);
}
