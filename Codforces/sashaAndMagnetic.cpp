//codeforces.com/contest/1113/problem/B]

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

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
typedef long double ld;

int main(){
	fastio

	int n;
	cin >> n;

	int a[n];
	fr(i, n) cin >> a[i];

	sort(a, a+n);
	reverse(a, a+n);

	int tsum = 0, mn = 666;
	fr(i, n) tsum += a[i], mn = min(mn, a[i]);

	vi divs[101];
	for (int i = 2; i <= 100; i++)
		for (int d = i-1; d > 1; d--)
			if (i%d == 0) divs[i].pb(d);

	int ans = tsum;
	fr(i, n-1){
		int aux = a[i];
		for (auto d : divs[aux]){
			int taux = tsum;
			taux -= aux;
			taux -= mn;
			taux += mn*d + aux/d;

			ans = min(ans, taux);
		}
	}
	
	cout << ans << endl;
}
