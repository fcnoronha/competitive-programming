// https://codeforces.com/problemset/problem/61/E

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

#define MAXN 1000009
ll bit[MAXN];

ll query(ll i){
	int ans = 0;
	for (; i > 0; i -= i&-i)
		ans += bit[i];
	return ans;
}

void update(ll i, ll x){
	for (; i < MAXN; i+=i&-i)
		bit[i] += x;
}

int main(){
	ll n;
	cin >> n;

	ll a[n], b[n];
	fr(i, n){
		ll x;
		cin >> x;

		a[i] = b[i] = x;
	}

	sort(b, b+n);
	//reverse(b, b+n);
	map<ll, ll> m;

	ll k = 1;
	fr(i, n)
		m[b[i]] = k++; 
	
	fr(i, n)
		a[i] = m[a[i]];

	ll ans = 0, aux[n+3], oporra[n+3];

	// Myself as a pivot, and I multiplie possibilities
	// Bigger to the left * lowe to the right
	fr(i, n){
		aux[i] = query(n) - query(a[i]);
		oporra[i] = query(a[i]-1);
		update(a[i], 1);
	}

	fr(i, n){
		ll d = (query(a[i]-1) - oporra[i]);
		ans += d*aux[i];
	}

	cout << ans << endl;
}
