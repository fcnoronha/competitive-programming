// br.spoj.com/problems/MANUT/

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

vi adj[409];
bool vis[409*409];
int cnt;

void dfs(int v){

	if (vis[v]) return;
	vis[v] = true;
	cnt++;

	for (auto u : adj[v])
		if (!vis[u]) dfs(u);
}

int main(){
	fastio

	int t = 1, n, m;

	while ((cin >> n >> m) &&  (n || m)){

		int x, y;

		frr(i, n) adj[i].clear();

		fr(i, m){
			cin >> x >> y;

			adj[x].pb(y);
			adj[y].pb(x);
		}

		vi ans;
		frr(i, n){

			// Reseting stuff
			ms(vis, 0);
			cnt = 0;

			vis[i] = 1;
			if (i == 1) dfs(2);
			else dfs(i-1);

			if (cnt < n-1) ans.pb(i);
		}

		cout << "Teste " << t++ << endl;
		if (ans.size() > 0){
			pv(ans);
		}
		else
			p(nenhum);

		cout << endl;
	}
}
