// https://www.spoj.com/problems/GERGOVIA/

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

int main(){
	ll n;
	while (cin >> n && n != 0){
		ll v[n+1];
		fr (i, n) cin >> v[i];
		ll ans = 0;
		frr (i, n-1){
			ans += abs(v[i-1]);
			v[i] += v[i-1]; 
		}
		cout << ans << endl;
	}
}
