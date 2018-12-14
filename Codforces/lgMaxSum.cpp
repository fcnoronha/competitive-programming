// codeforces.com/problemset/problem/276/C

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
typedef vector<ll> vi;

int main(){
	fastio

	ll n, q;
	cin >> n >> q;

	vi a(n+2, 0), f(n+2, 0);

	fr(i, n)
		cin >> a[i];

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	fr(i, q){
		ll l,r;
		cin >> l >> r;
		f[l]++;
		f[r+1]--;
	}

	frr(i, n+1)
		f[i] += f[i-1];

	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());

	ll ans = 0;
	fr(i, n+2)
		ans += f[i]*a[i];

	cout << ans << endl; 
}
