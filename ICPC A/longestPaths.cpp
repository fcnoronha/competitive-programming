//uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=941F

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

#define MAXN 109

vi adj[MAXN];
int order[MAXN];
vi lst;
pii ans[MAXN]; // maxdist - origin
int n, t = 1;

void topoSort(){

	frr (i, n){
		if (order[i] == 0)
			lst.pb(i);
	}

	int beg = 0;
	while (lst.size() > beg){
		int t = lst[beg];
		beg++;

		for (int i : adj[t]){
			order[i]--;
			if (order[i] == 0) lst.pb(i);
		}
	}

	fr(i, n){
		int v = lst[i];

		if (ans[v].s == 1)
			ans[v] = {0, -v};

		for (auto u : adj[v]){
			pii aux = ans[v];
			aux.f++;

			if (ans[u] < aux)
				ans[u] = aux;
		}
	}
}

int main(){

	while (cin >> n && n) {

		// Resseting stuff
		fr(i, MAXN){
			adj[i].clear();
			ans[i] = {-1, 1};
		}
		ms(order, 0);
		lst.clear();

		int r;
		cin >> r;

		int u, v;
		while (cin >> u >> v && (u || v))
			adj[v].pb(u), order[u]++;

		topoSort();

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", \
			t++, r, ans[r].f, -ans[r].s);

	}

}
