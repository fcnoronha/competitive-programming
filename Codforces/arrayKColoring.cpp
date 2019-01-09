// codeforces.com/contest/1102/problem/B

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

bool memo[5009][5009];

int main(){
	fastio
	
	int n, k;
	cin >> n >> k;

	vi freq(5009, 0);
	int a[n];
	fr(i, n) cin >> a[i], freq[a[i]]++;

	fr(i, 5007){
		if (freq[i] > k){
			p(NO);
			return 0;
		}
	}

	p(YES);
	fr(i, 5006) fr(j, 5009) memo[i][j] = 0;

	int cnt = 1;
	vector<bool> rsrs(n, false);
	
	while (cnt <= k){
		fr(i, n){
			if (rsrs[i]) continue;

			memo[a[i]][cnt] = 1;
			rsrs[i] = 1;
			a[i] = cnt;
			cnt++;
			if (cnt > k) break;
		}
	}	

	fr(i, n){

		if (rsrs[i]) continue;

		int color = 1;
		while (memo[a[i]][color]) color++;
		memo[a[i]][color] = 1;
		a[i] = color;
	}

	fr(i, n) cout << a[i] << " ";
	cout << endl;
}
