// codcad.com/problem/168

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

int memo[1009][1009];
vector<pii> box;

int dp(int ind, int h){

	if (h == 0) return 200009;

	if (ind == 0){
		if (h == 1) return box[ind].f - box[ind].s;
		return -200009;
	}

	int &pdm = memo[ind][h];
	if (pdm != -1) return pdm;

	int resit = box[ind].f - box[ind].s;
	int dont = dp(ind-1, h);
	int prev = dp(ind-1, h-1);

	return pdm = max(dont, min(prev-box[ind].s, resit));
}

int main(){
	fastio
	
	int n;
	cin >> n;

	box.resize(n);
	fr(i, n) cin >> box[i].s >> box[i].f;

	sort(all(box));
	reverse(all(box));

	fr(i, n+1) fr(j, n+1) memo[i][j] = -1;

	frr(i, n) dp(n-1, i);

	int ans = -1;
	frr(i, n)
		if (memo[n-1][i] >= 0) ans = i;

	cout << ans << endl;
}
