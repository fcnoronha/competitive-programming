#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << "\n";

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

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		string s;
		vector<pii> itv[10009];
		string names[10009];
		vector<string> ans;
		unordered_map<string, int> mp;

		int cnt = 0, ini, fim, v;
		while (n--) {
			// fuck u
			cin >> s;
			cin >> ini >> fim >> v;

			while (v--) {

				cin >> s;

				if (mp.count(s) == 0) {
					names[cnt] = s;
					mp[s] = cnt++;
				}

				itv[ mp[s] ].pb({ini, 1});
				itv[ mp[s] ].pb({fim+1, -1});
			}
		}

		fr(i, cnt + 2) {

			sort(all(itv[i]));

			int oi = 0;

			for (auto p : itv[i]) {
				oi += p.s;

				if (oi > 1) {
					ans.pb(names[i]);
					break;
				}
			}
		}

		p(ans.size());
		sort(all(ans));
		pv(ans);
	}
}
