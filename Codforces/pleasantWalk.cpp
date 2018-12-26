// https://codeforces.com/contest/1090/problem/M

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
	ll n, k;
	cin >> n >> k;

	ll aux = 0, ans = 0, ant;
	fr(i, n){
		if (i == 0) cin >> ant, aux = 1;
		else {
			ll x; cin >> x;
			if (x != ant) {
				aux++;
				ant = x;
			}
			else {
				ans = max(ans, aux);
				aux = 1ll;
			}
		}
	}

	if (aux > 0) ans = max(ans, aux);

	cout << ans << endl;	
}
