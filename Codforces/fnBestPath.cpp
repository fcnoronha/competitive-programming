// https://codeforces.com/contest/1084/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


ll w[300009], ans;
vector< pair<ll,ll> > adj[300009];

ll dfs(ll v, ll anc){
	ll aux = w[v];
	ans = max(ans, aux);

	for (auto u : adj[v]){
		if (u.f == anc) continue;
		ll d = dfs(u.f, v) - u.s;
		ans = max(ans, d + aux);
		aux = max(aux, d + w[v]);
		// aux = max(aux, d + aux);
	}

	return aux;
}

int main(){
	fastio

	ll n; cin >> n;

	frr(i, n) cin >> w[i];

	ll u, v, c;
	fr(i, n-1){
		cin >> u >> v >> c;

		adj[u].pb({v,c});
		adj[v].pb({u,c});
	}

	dfs(1, 0);
	cout << ans << endl;
}
