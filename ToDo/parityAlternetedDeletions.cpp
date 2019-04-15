// codeforces.com/contest/1144/problem/B

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

	vi p, i;
	fr(j, n){
		int x;
		cin >> x;

		if (x%2 == 0) p.pb(x);
		if (x%2 == 1) i.pb(x);
	}

	sort(all(i));
	sort(all(p));

	if (p.size() == i.size()){
		p(0);
		return 0;
	}

	while (i.size() > 0 && p.size() > 0){
		i.pop_back();
		p.pop_back();
	}

	if (i.size() > 0){
		i.pop_back();
		int ans = 0;
		fr(j, i.size())
			ans += i[j];

		cout << ans << endl;
		return 0;
	}

	p.pop_back();
	int ans = 0;
	fr(j, p.size())
		ans += p[j];

	cout << ans << endl;
	return 0;
}
