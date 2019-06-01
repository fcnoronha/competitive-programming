// codeforces.com/problemset/problem/603/B

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

#define maxn 1000100
const ll mod = 1e9+7;

ll id[maxn], sz[maxn], c;

ll find(ll p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(ll p, ll q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	c--;
	id[p] = q;
	sz[q] += sz[p];
}


ll fastexp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2) {
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		exp /= 2;
	}
	return ans;
}

int main(){
	fastio

	ll p, k;
	cin >> p >> k;

	if (k == 0ll) {
		cout << fastexp(p, p-1) << endl;
		return 0;
	}

	if (k == 1ll) {
		cout << fastexp(p, p) << endl;
		return 0;
	}

	fr(i, maxn) id[i] = i, sz[i] = 1;
	c = p-1;

	for (ll i = 1ll; i < p; i++) {
		ll j = (k * i) % p;
		uni(i, j);
	}

	cout << fastexp(p, c) << endl;

}
