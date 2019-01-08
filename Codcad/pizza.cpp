// codcad.com/problem/139

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

int val[100009];
vi sum(100009, 0);
vi best(100009, 0);

int main(){
	fastio
	
	int n;
	cin >> n;

	fr(i, n) cin >> val[i];

	fr(i, n){
		sum[i+1] = sum[i] + val[i];
		best[i+1] = max(best[i], sum[i+1]);
	}

	int ans = 0;
	fr(i, n+1){
		ans = max(ans, best[i] + (sum[n] - sum[i]));
	}
	
	int aux = 0;
	fr(i, n){
		int tmp = aux;
		aux = max(0, tmp + val[i]);
		ans = max(ans, aux);
	}

	cout << ans << endl;
}
