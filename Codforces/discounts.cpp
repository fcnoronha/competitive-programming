// codeforces.com/contest/1132/problem/B

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

bool comp(ll a, ll b){
	return b < a;
}

int main(){
	fastio

	ll n;
	cin >> n;

	ll a[n], mx = 0ll;
	fr(i, n)
		cin >> a[i], mx += a[i];

	sort(a, a+n, comp);

	ll m;
	cin >> m;
	ll x;
	fr(i, m){
		cin >> x;

		cout << mx - a[x-1] << endl;
	}
}
