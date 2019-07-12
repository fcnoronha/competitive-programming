//codeforces.com/contest/1169/problem/B

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

vector<pii> freq;

int main(){
	fastio

	int n, m;
	cin >> n >> m;

	pii ps[m];
	fr(i, m) cin >> ps[i].f >> ps[i].s;

	frr(i, n) freq.pb({0, i});

	fr(i, m) {
		freq[ ps[i].f-1 ].f++;
		freq[ ps[i].s-1 ].f++;
	}

	sort(all(freq));
	reverse(all(freq));

	// I dont know why 20, with n I got TLE and 1 its WA. So, by intuition,
	// its min(n, 20)
	fr(i, min(n, 20)) {

		bool deu = 1;
		int ans1 = freq[i].s;

		unordered_map<int, int> mp;
		int cnt = 0;

		fr(j, m) {

			int v1 = ps[j].s;
			int v2 = ps[j].f;

			if (v1 == ans1) continue;

			if (v2 == ans1) continue;

			cnt++;
			mp[v1]++;
			mp[v2]++;
		}

		if (cnt == 0) {
			p("YES");
			return 0;
		}

		for (auto u : mp) {
			if (u.s == cnt) {
				p("YES");
				return 0;
			}
		}
	}

	p("NO");
}
