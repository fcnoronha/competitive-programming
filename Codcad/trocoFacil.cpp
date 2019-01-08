// codcad.com/problem/50

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
	
	int n;
	cin >> n;

	int qtd[2000000];

	fr(i, n+1) qtd[i] = 2000000;

	int val[6] = {1, 5, 10, 25, 50, 100};

	qtd[0] = 0;
	fr(i, n+1)
		fr(j, 6)
			qtd[i+val[j]] = min(qtd[i]+1, qtd[i+val[j]]);

	cout << qtd[n] << endl;
}
