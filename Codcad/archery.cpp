// codcad.com/problem/74

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll ic(vector<ll> &v){

	ll inv = 0;

	if (v.size() == 1) return 0;

	vector<ll> u1, u2;

	for (ll i = 0; i < v.size()/2; i++)
		u1.push_back(v[i]);

	for (ll i = v.size()/2; i < v.size(); i++)
		u2.push_back(v[i]);

	inv += ic(u1);
	inv += ic(u2);

	u1.push_back(INT_MAX);
	u2.push_back(INT_MAX);

	ll ini1 = 0, ini2 = 0;

	for (ll i = 0; i < v.size(); i++){

		if (u1[ini1] < u2[ini2])
			v[i] = u1[ini1++];

		else {
			v[i] = u2[ini2++];
			inv += u1.size() - ini1 - 1;
		}
	}
	return inv;
}


int main(){
	fastio
	
	int n;
	cin >> n;

	vl dist;
	vl auxx;
	fr(i, n){
		ll x, y;
		cin >> x >> y;

		ll aux = x*x + y*y;
		dist.pb(aux);
		auxx.pb(aux);
	}

	sort(auxx.begin(), auxx.end());
	reverse(auxx.begin(), auxx.end());
	map<ll,ll> m;

	int cnt = 1ll;
	fr(i, n){
		if (i > 0 && auxx[i] == auxx[i-1]) continue;
		m[auxx[i]] = cnt++;
	}

	fr(i, n) dist[i] = m[dist[i]];

	cout << ic(dist) << endl;
}
