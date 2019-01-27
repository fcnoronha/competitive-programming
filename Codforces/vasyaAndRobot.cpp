//codeforces.com/contest/1073/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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

int main(){
	fastio
	
	ll n, t;
	cin >> n >> t;

	ll tsum = 0ll, x, mn = LLONG_MAX;
	pll val[n];

	fr(i, n){

		cin >> val[i].f;
		val[i].s = 1;
		mn = min(mn, val[i].f);
	}

	ll ans = 0ll;
	while (t >= mn){

		tsum = 0ll;

		ll cnt = 0ll, auxt = t;
		fr(i, n){

			if (!val[i].s) continue;
			
			if (val[i].f > auxt){
				val[i].s = 0;
				continue;
			}

			cnt++;
			tsum += val[i].f;
			auxt -= val[i].f;
		}

		ans += (t/tsum)*cnt;
		t %= tsum;
	}

	cout << ans << endl;
}
