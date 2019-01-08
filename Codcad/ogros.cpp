// codcad.com/problem/52

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
	
	int n, m;
	cin >> n >> m;

	vl a;
	a.pb(0);
	fr(i, n-1){
		ll x;
		cin >> x;
		a.pb(x); 
	}

	ll f[n];
	fr(i, n) cin >> f[i];

	vl ans;
	fr(i, m){
		ll o;
		cin >> o;

		int faixa = (upper_bound(a.begin(), a.end(), o) - a.begin()) - 1;
		//if ( binary_search(a.begin(), a.end(), o) ) faixa--;
		//dbg(faixa);
		ans.pb(f[faixa]);
	}

	fr(i, m){
		cout << ans[i];
		if (i < m-1) cout << " ";
		else cout << endl;
	}
}
