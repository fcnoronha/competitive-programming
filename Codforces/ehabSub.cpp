// https://codeforces.com/contest/1088/problem/B

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
	fastio;
	ll n, k, ac = 0;
	cin >> n >> k;

	vector<ll> a;

	fr(i, n){
		ll x;
		cin >> x;
		a.pb(x);
	}

	sort(a.begin(), a.end());

	int ind = 0;
	fr(i, k){
		while (ind < n && a[ind] - ac <= 0)
			ind++;

		if (ind == n){
			cout << 0 << endl;
			continue;
		}

		cout << a[ind] - ac << endl;
		ac += (a[ind] - ac);
	}
}
