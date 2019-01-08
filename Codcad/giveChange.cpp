// codcad.com/problem/135

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

	vi coins;
	fr(i, n){
		int x;
		cin >> x;

		if (x > 1000) continue;
		coins.pb(x);
	}

	vector<bool> can(1009, false);
	fr(i, m+1)
		fr(j, coins.size())
			if (i*can[i] + coins[j] < 1002)
				can[i*can[i] + coins[j]] = true;
		
	if (can[m]) p(S);
	else p(N);
}
