//codeforces.com/contest/1106/problem/B

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
	
	int n, m;
	cin >> n >> m; // food - client

	int a[n]; // amount i
	fr(i, n) cin >> a[i];

	pii c[n]; // cost - index
	int auxc[n]; // cost without orderirng;
	fr(i, n) cin >> c[i].f, c[i].s = i, auxc[i] = c[i].f;

	sort(c, c+n);

	int index = 0; // index of cheapest available food;

	int t, d;
	fr(i, m){

		ll ans = 0;

		cin >> t >> d;
		t--;

		if (a[t] >= d){

			a[t] -= d;
			ans = (ll)auxc[t]*d;

			cout << ans << endl;
			continue;
		}

		ans = (ll)a[t]*auxc[t];
		d -= a[t];
		a[t] = 0;

		while (index < n && d > 0){

			int auxi = c[index].s;

			if (a[auxi] >= d){

				a[auxi] -= d;
				ans += (ll)d*auxc[auxi];
				d = 0;
			}

			else {

				d -= a[auxi];
				ans += (ll)a[auxi]*auxc[auxi];
				a[auxi] = 0;
			}

			index += (a[auxi] == 0);
		}

		if (index == n && d > 0){
			p(0);
			continue;
		}

		cout << ans << endl;
	}
}
