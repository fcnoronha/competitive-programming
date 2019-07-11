//codeforces.com/contest/1150/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio

	int n, m, r;
	cin >> n >> m >> r;

	int mx = INT_MIN, mn = INT_MAX, aux;
	fr(i, n) {
		cin >> aux;
		mn = min(mn, aux);
	}
	fr(i, m) {
		cin >> aux;
		mx = max(mx, aux);
	}

	if (mx <= mn) {
		p(r);
		return 0;
	}

	int ans = r/mn;
	ans *= mx;
	p(ans + r%mn);
}
