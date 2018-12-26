// https://codeforces.com/contest/1092/problem/B

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
	
	int n;
	cin >> n;

	int a[n];
	fr(i, n) cin >> a[i];
	sort(a, a+n);

	int ans = 0;
	fr(i, n){
		ans += a[i+1] - a[i];
		i++;
	}

	cout << ans << endl;
}

