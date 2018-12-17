// https://www.spoj.com/problems/INVCNT/

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

#define MAXN 200005
ll bit[200009];

ll query(ll i){
	ll sum = 0;
    for (; i > 0; i -= i&-i) 
    	sum += bit[i];
    return sum;
}

void update(ll x, ll i){
	for (; i < MAXN; i += i&-i)
		bit[i] += x;
}

int main(){
	fastio

	ll t;
	cin >> t;

	while (t--){

		ll n;
		cin >> n;

		ll a[n+n];
		frr(i, n){
			bit[i] = 0;
			cin >> a[i];
		}

		ll ans = 0;
		for (ll i = n; i > 0; i--){
			ans += query(a[i] - 1);
			update(1, a[i]);
		}

		cout << ans << endl;
	}

	
}