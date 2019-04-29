// www.codechef.com/JAN17/problems/CAPIMOVE

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

#define MAXN 50009

vi adj[MAXN];
int p[MAXN];
int ans[MAXN];
bool vis[MAXN];
set<pii> st;

void dfs(int v) {

	if (vis[v]) return;
	vis[v] = 1;
	ans[v] = 0;

	vi aux;
	for (auto u : adj[v])
		aux.pb(p[u]);

	aux.pb(p[v]);
	sort(all(aux));

	for (auto x : st) {

		if (!binary_search(all(aux), -x.f)){
			ans[v] = x.s;
			break;
		}
	}

	for (auto u : adj[v]) {
		dfs(u);
	}
}

int main(){
	fastio

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;

		st.clear();
		frr(i, n) {
			adj[i].clear();
			cin >> p[i];
			st.insert({-p[i], i});
			vis[i] = 0;
		}

		fr(i, n-1){
			int u, v;
			cin >> u >> v;

			adj[u].pb(v);
			adj[v].pb(u);
		}

		dfs(1);

		frr(i, n) cout << ans[i] << " ";
		cout << endl;
	}
}
