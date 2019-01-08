// codcad.com/problem/136

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

	vi qtd(1009, INT_MAX);
	fr(j, coins.size()) qtd[coins[j]] = 1;

	fr(i, m+1){
		fr(j, coins.size()){
			if (qtd[i] == INT_MAX) continue;
			if (i + coins[j] > 1002) continue;

			qtd[i + coins[j]] = min(qtd[i+coins[j]], qtd[i]+1);
		}
	}
		
	if (qtd[m] < 10) p(S);
	else p(N);

}
