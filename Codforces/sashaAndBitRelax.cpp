//codeforces.com/contest/1113/problem/C

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

ll f[2][2<<21];

int main(){
	fastio

	int n;
	cin >> n;

	ll a[n];
	fr(i, n) cin >> a[i];

	f[1][0] = 1;
	ll xoxo = 0;
	ll ans = 0;
	fr(i, n){
		xoxo ^= a[i];
		ans += f[i%2][xoxo]++;
	}

	cout << ans << endl;
}
