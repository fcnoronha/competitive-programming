// https://codeforces.com/contest/1087/problem/B

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
	
	int n, k, x = 0;
	cin >> n >> k;

	for (int i = k-1; i > 0; i--){
		if (n%i) continue;
		ll ans = (n/i)*k + i;
		cout << ans << endl;
		return 0;
	}

}
