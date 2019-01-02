// http://codeforces.com/contest/1065/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll n, k, mx = 0, mn = INT_MAX, x, h[200009];

int main(){
	cin >> n >> k;

	fr(i, n){
		cin >> x;
		mx = max(mx, x);
		mn = min(mn, x);
		h[x]++;
	}

	for (int i = mx; i >= 0; i--)
		h[i] += h[i+1];

	ll ans = 0, ac = 0;
	for (int i = mx; i > mn; i--){
		if (ac + h[i] <= k)
			ac += h[i];
		else{
			ac = h[i];
			ans++;
		}
	}
	if (ac > 0) ans++;

	cout << ans << endl;
}
