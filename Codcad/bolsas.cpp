// codcad.com/problem/51

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

	pii times[n]; // deadline , duration
	fr(i, n) cin >> times[i].s >> times[i].f;

	sort(times, times+n);

	int ans = 0, sum = 0;
	fr(i, n){
		ans = max(0, sum + times[i].s - times[i].f);
		sum += times[i].s;
	}

	cout << ans << endl;
}
