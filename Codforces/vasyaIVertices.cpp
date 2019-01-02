// http://codeforces.com/contest/1065/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(ll i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll m, n;

int main(){
	cin >> n >> m;

	if (n == 1){
		cout << 1 << " " << 1 << endl;
		return 0;
	}	

	ll mx,i = 0;
	while(1){
		if (i*(i-1ll) >= 2ll*m){
			mx = max(0ll, n-i);
			break;
		}
		i++;
	}

	ll mn = max(0ll, n-(2*m));

	cout << mn << " " << mx << endl;
}
