// https://codeforces.com/contest/1061/problem/B

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
	ll n, m, totals = 0, maxh = 0, x, a[100008];

	cin >> n >> m;
	fr(i, n){
		cin >> a[i];
		maxh = max(maxh, a[i]);
		totals += a[i];
	}

	sort(a, a+n);

	ll sum = 0, h = 0;
	fr(i, n-1){
		h = min(a[i], h+1);
	}

	sum = a[n-1] - h + n - 1;
	if (h == a[n-1]) sum ++;

	cout << totals - sum << endl;

}
