// http://codeforces.com/gym/101908/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(ll i=0;i<n;i++)
#define frr(i,n) for(ll i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

ll ic(vector<pii> &v){
	ll inv = 0;
	if(v.size() == 1) return 0;

	vector<pii> u1, u2;

	for (ll i = 0; i < v.size()/2; i++){
		u1.pb(v[i]);
	}
	
	for (ll i = v.size()/2; i < v.size(); i++)
		u2.pb(v[i]);

	inv += ic(u1);
	inv += ic(u2);

	u1.pb({INT_MAX, INT_MAX});
	u2.pb({INT_MAX, INT_MAX});

	ll ini1 = 0, ini2 = 0;

	fr(i, v.size()){
		if(u1[ini1].s <= u2[ini2].s)
			v[i] = u1[ini1++];
		else {
			v[i] = u2[ini2++];

			inv += u1.size() - ini1 - 1;
		}
	}

	return inv;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll h, k;
	vector<pii> v1, v2;


	cin >> h >> k;
	cin >> h >> k;

	fr (i, h){
		ll a, b;
		cin >> a >> b;
		v1.pb({a,b});
	}

	sort(v1.begin(), v1.end());


	fr (i, k){
		ll a, b;
		cin >> a >> b;
		v2.pb({a,b});
	}

	sort(v2.begin(), v2.end());

	ll ans = ic(v1) + ic(v2) + h + k + (h*k) + 1;

	cout << ans << endl;
}