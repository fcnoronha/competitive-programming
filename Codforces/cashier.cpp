// http://codeforces.com/contest/1059/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(long long int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll n, l[100008], a, ans = 0, t[100008],x;	

int main(){
	
	cin >> n >> x >> a;

	fr(i, n){
		cin >> t[i] >> l[i];
		if (i > 0){
			ans += (t[i]-(t[i-1]+l[i-1]))/a;
		}
		if (i == 0){
			ans += t[i]/a;
		}
	}

	ans += (x-(t[n-1]+l[n-1]))/a;
	cout << ans << endl; 
}
