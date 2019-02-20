// uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2499

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

#define MAXN 100009

bool isv[MAXN];
vi adj[MAXN];
vi tSort;

void dfs(int v){

	isv[v] = 1;

	for (auto u : adj[v]){
		if (isv[u]) continue;
		dfs(u);
	}

	tSort.pb(v);
}

int main(){
	fastio
	
	int t;
	cin >> t;

	while (t--){
		ms(isv, 0);
		fr(i, MAXN) adj[i].clear();
		tSort.clear();

		int n, m;
		cin >> n >> m;

		int x, y;
		fr(i, m){
			cin >> x >> y;
			adj[x].pb(y);
		}

		frr(i, n) if (!isv[i]) dfs(i);

		reverse(all(tSort));
		ms(isv, false);

		int ans = 0;
		fr(i, n){
			int u = tSort[i];

			if (isv[u]) continue; 
			dfs(u);
			ans++;
		}

		cout << ans << endl;
	}
}
