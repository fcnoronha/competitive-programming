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

vi adj[100009];
bool vis[100009];

void dfs(int v, vi &oi) {

	if (vis[v])	return;
	vis[v] = 1;

	oi.pb(v);

	for (auto u : adj[v])
		dfs(u, oi);
}

int main(){
	fastio

	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		int cnt = 0;
		map<string, int> mp;
		string rev[100009];
		string s, aux;

		fr(i, n) {

			cin >> s;
			rev[cnt] = s;
			adj[cnt].clear();
			mp[s] = cnt++;

			int c;
			cin >> c;

			while (c--) {

				cin >> aux;

				adj[ cnt-1 ].pb(mp[aux]);
			}
		}

		vi ans1;
		ms(vis, 0);
		while (k--) {

			cin >> aux;
			dfs(mp[aux], ans1);

		}

		sort(all(ans1));
		string ans[ans1.size()];
		fr(i, ans1.size())
			ans[i] = rev[ans1[i]];

		fr(i, ans1.size())
			p(ans[i]);
 	}
}
