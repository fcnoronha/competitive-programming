// https://codeforces.com/contest/1061/problem/C

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

const int mod=1e9+7;

int main(){
	fastio;
	ll n, x, memo[1000009], ans = 0;

	cin >> n;
	memo[0] = 1;

	frr(i, n){
		cin >> x;

		vi cur;

		for(int j = 1; j*j <= x; j++){
			if (x%j == 0){
				cur.pb(j);
				if (j != x/j) cur.pb(x/j);
			}
		}

		sort(cur.begin(), cur.end());
		reverse(cur.begin(), cur.end());
		for (int u : cur)
			memo[u] = (memo[u] + memo[u-1])%mod;		
	}
	frr(i, n) ans = (ans + memo[i])%mod;
	cout << ans << endl;
}
