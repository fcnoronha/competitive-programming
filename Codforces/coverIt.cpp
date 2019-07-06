//codeforces.com/contest/1176/problem/E

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

#define maxn 200009

const int INF = 0x3f3f3f3f;
int dist[maxn];
vi adj[maxn];
int m, n;

void bfs(int r) {

	memset(dist, INF, (n+2)*sizeof(int));
	dist[r] = 0;

	queue<int> q;
	q.push(r);

	while (!q.empty()) {

		int v = q.front();
		q.pop();

		for (auto u : adj[v])
			if (dist[u] == INF)
				dist[u] = dist[v] + 1, q.push(u);
	}
}

int main(){
	fastio

	int t;
	cin >> t;

	while (t--) {

		cin >> n >> m;

		frr(i, n)
			adj[i].clear();

		int a, b;
		fr(i, m) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		bfs(1);
		vi par, imp;
		frr(i, n) {
			if (dist[i]%2) imp.pb(i);
			else par.pb(i);
		}

		if (par.size() < imp.size()){
			cout << par.size() << endl;
			pv(par);
		}
		else {
			cout << imp.size() << endl;
			pv(imp);
		}

	}

}
