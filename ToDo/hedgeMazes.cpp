//icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3807

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

#define MAXN 10009

vi adj[MAXN];
int mx[MAXN];
int r, c, q;

int main(){
	fastio

	while (cin >> r >> c >> q && (r || c || q)){

		// Resseting stuffs
		fr(i, MAXN) adj[i].clear();
		ms(mx, 0);

		// Reading graph
		int u, v;
		fr(i, c){
			cin >> u >> v;

			adj[u].pb(v);
			adj[v].pb(u);
		}

		// Doing graph traverse
		frr(i, r)
			for (auto u : adj[i])
				if (u == i+1)
					mx[u] = mx[i]+1;

		// Aswering queries
		int a, b;
		fr(i, q){
			cin >> a >> b;

			if (b <= a || b-mx[b] > a)
				p(N);
			else
				p(Y);
		}

		p(-);
	}
}
