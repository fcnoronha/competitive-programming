// https://codeforces.com/contest/1041/problem/D

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

	ll n, h, ans = 0ll;

	cin >> n >> h;

	vi v;

	int ant;
	fr(i, n){
		int a, b;
		cin >> a >> b;

		if (i > 0)
			v.pb(a-ant);
		
		v.pb(b-a);
		ant = b;
	}

	v.pb(INT_MAX);

	ll k = 1, ansss = 0;
	for (ll i = 0; i < v.size(); i += 2){

		if (i > 0){
			h += v[i-1];
			ansss -= v[i-1];
			ansss -= v[i-2];
		}

		while (h - v[k] > 0){
			h -= v[k];
			ansss += v[k-1] + v[k];
			k += 2;
		}

		ll aux = 0;
		if (h > 0){
			aux = v[k-1];
			aux += h;
		}

		ans = max(ans, ansss+aux);
	}

	cout << ans << endl;
}
