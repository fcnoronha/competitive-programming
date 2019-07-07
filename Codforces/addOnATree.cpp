//codeforces.com/contest/1189/problem/D1

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

int main(){
	fastio

	int n;
	cin >> n;

	vi adj[n+10];
	int u, v;
	bool opa = true;

	fr(i, n-1) {
		cin >> u >> v;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	frr(i, n)
		if (adj[i].size() == 2 || adj[i].size() == 2)
			opa = 0;

	if (opa) p(YES);
	else p(NO);
}
