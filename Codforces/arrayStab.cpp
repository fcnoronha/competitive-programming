// https://codeforces.com/contest/1095/problem/B

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	fastio
	
	int n; cin >> n;

	int a[n], b[n];
	fr(i, n) cin >> a[i], b[i] = a[i];

	int mn = INT_MAX;
	// fr(i, n) mn = min(mn, a[i]);

	int mx = 0;
	fr(i, n) mx = max(mx, a[i]);

	fr(i, n) if (a[i] == mx && mx != -1) a[i] = mx = -1;

	mn = INT_MAX, mx = 0;
	fr(i, n) if(a[i] > 0) mn = min(mn, a[i]), mx = max(mx, a[i]);


	int ans1, ans2;
	ans1 = mx-mn;
	
	mn = INT_MAX;
	fr(i, n) mn = min(mn, b[i]);

	mx = 0;
	//fr(i, n) mx = max(mx, a[i]);

	fr(i, n) if (b[i] == mn && mn != -1) b[i] = mn = -1;

	mn = INT_MAX, mx = 0;
	fr(i, n) if(b[i] > 0) mn = min(mn, b[i]), mx = max(mx, b[i]);

	ans2 = mx-mn;

	cout << min(ans1, ans2) << endl;
}
