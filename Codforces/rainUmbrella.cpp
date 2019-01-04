// codeforces.com/contest/988/problem/F

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

int rain[2009], umb[2009];

int main(){
	fastio

	int a, n, m;
	cin >> a >> n >> m;

	fr(i, n){
		int l, r;
		cin >> l >> r;
		rain[l]++;
		rain[r]--;
	}

	frr(i, 2002) rain[i] += rain[i-1];

	int w[m+1];
	frr(i, m){
		int x, p;
		cin >> x >> p;
		if (umb[x] == 0) umb[x] = i;
		else if (w[umb[x]] > p) umb[x] = i;
		w[i] = p;
	}

	int dp[2009][m+1];
	fr(i, 2009)
		fr(j, m+1)
			dp[i][j] = INT_MAX;

	dp[0][0] = 0;

	fr(i, a){
		for (int j = m; j >= 0; j--){

			if (dp[i][j] == INT_MAX) continue;
			if (!rain[i]) dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
			if (j > 0) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + w[j]);
			if (umb[i]) dp[i+1][umb[i]] = min(dp[i+1][umb[i]], dp[i][j] + w[umb[i]]);

		}
	}

	int ans = INT_MAX;
	fr(i, m+1) ans = min(ans, dp[a][i]);

	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}
