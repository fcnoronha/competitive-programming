// codeforces.com/contest/1096/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
#define p(x) cout << #x << endl

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
	
	ll n;
	string s, t = "hard";
	cin >> n;
	cin >> s;

	ll a[n];
	fr(i, n) cin >> a[i];

	ll dp[n+1][5];
	fr(i, n+1) fr(j, 5) dp[i][j] = (INT_MAX)*n;

	dp[0][0] = 0ll;

	fr(i, n) fr(j, 4){
		// dbg(dp[i][j]);
		dp[i+1][j + (s[i] == t[j])] = min(dp[i+1][j + (s[i] == t[j])], dp[i][j]);
		dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i]);
		//dbg(dp[i][j]);
	}

	ll ans = LLONG_MAX;
	fr(i, 4) ans = min(ans, dp[n][i]);

	cout << ans << endl;	
}
