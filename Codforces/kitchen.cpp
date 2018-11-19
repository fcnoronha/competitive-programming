// http://codeforces.com/contest/1079/problem/A

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

int n, k, a[106], mx;

int main(){
	cin >> n >> k;

	fr(i, n){
		int x;
		cin >> x;
		a[x]++;
		mx = max(mx, a[x]);
	}

	int set = mx/k;
	if (mx%k > 0) set++;

	int nu = 0, nt = 0;
	for (int i = 1; i <= 100; i++){
		if (a[i] > 0){
			nu++;
			
		}
	}

	int ans = (nu * set * k) - n;
	cout << ans << endl;
}
