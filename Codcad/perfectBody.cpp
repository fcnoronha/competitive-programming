// codcad.com/problem/67

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

ll dp[2009][2009], n, p;
pll v[2009]; // weigth , value

ll knapsack(int obj, int wg_max){
	if (dp[obj][wg_max] >= 0) return dp[obj][wg_max];

	if (obj == n || !wg_max) return dp[obj][wg_max] = 0;

	int dont = knapsack(obj+1, wg_max);

	if (v[obj].f <= wg_max){
		int put = v[obj].s + knapsack(obj+1, wg_max - v[obj].f);

		return dp[obj][wg_max] = max(put, dont);
	}

	return dp[obj][wg_max] = dont;
}

int main(){
	fastio
	
	cin >> p >> n;

	fr(i, n) cin >> v[i].f >> v[i].s;


	fr(i, n+1) fr(j, p+1) dp[i][j] = -1;

	cout << knapsack(0, p) << endl;
}
