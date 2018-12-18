// https://codeforces.com/contest/295/problem/A

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

typedef struct {
	ll l, r, d;
} o;
	

int main(){
	fastio

	ll n, m, k;
	cin >> n >> m >> k;

	ll v[n];
	fr(i, n) cin >> v[i];

	o op[m];
	fr(i, m) cin >> op[i].l >> op[i].r >> op[i].d;

	vector<ll> freq(m+2, 0);
	vector<ll> ac(n+2, 0);
	fr(i, k){
		ll a, b;
		cin >> a >> b;

		freq[a]++;
		freq[b+1]--;
	}

	frr(i, m) freq[i] += freq[i-1];

	fr(i, m){
		ll l = op[i].l;
		ll r = op[i].r+1;
		ll d = op[i].d*freq[i+1];

		ac[l] += d;
		ac[r] -= d;
	} 

	frr(i, n) ac[i] += ac[i-1];
	fr(i, n) v[i] += ac[i+1];

	for (auto u : v) cout << u << " ";

	cout << endl;
}
