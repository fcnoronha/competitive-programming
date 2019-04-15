// codeforces.com/contest/1140/problem/C

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

	ll n, k;
	cin >> n >> k;

	pll s[n];
	fr(i, n)
		cin >> s[i].s >> s[i].f;

	sort(s, s+n);

	ll ans = 0ll, sm = 0ll;

	set<pll> st;

	for (int i = n-1; i >= 0; i--){

		st.insert({s[i].s, i});
		sm += s[i].s;

		if (st.size() > k){
			auto it = st.begin();
			sm -= (*it).f;
			st.erase(it);
		}

		ans = max(ans, sm * s[i].f);
	}

	cout << ans << endl;
}
