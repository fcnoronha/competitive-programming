// codeforces.com/problemset/problem/816/B

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

#define MAXN 200009

int ac[MAXN];

int main(){
	fastio

	ll n, k, q;
	cin >> n >> k >> q;

	ll l, r;
	fr(i, n){
		cin >> l >> r;
		ac[l]++; ac[r+1]--;
	}

	frr(i, MAXN-1)
		ac[i] += ac[i-1];
	

	fr(i, MAXN)
		ac[i] = (ac[i] >= k);

	frr(i, MAXN-1)
		ac[i] += ac[i-1];


	ll ans = 0;
	fr(i, q){
		cin >> l >> r;

		cout << ac[r] - ac[l-1] << endl;
	}
}
