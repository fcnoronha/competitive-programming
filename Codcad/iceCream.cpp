// codcad.com/problem/58

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
	
	int p, s;
	cin >> p >> s;

	vi praia(p+p, 0);
	fr(i, s){
		int u, v;
		cin >> u >> v;

		praia[u]++;
		praia[v]--;
	}

	frr(i, praia.size()-1) praia[i] += praia[i-1];

	fr(i, praia.size()){

		if (praia[i] > 0){
			int ini = i;
			while (praia[i] > 0) i++;
			cout << ini << " " << i << endl;
		}
	}
}
