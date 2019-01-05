//codeforces.com/contest/1099/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

vl adj[200009];
ll sum[200009];

bool dfs1(ll v, ll s){

	if (sum[v] > 0 && sum[v] < s){
		return false;
	} 

	bool deu = true;
	for (auto u : adj[v])
		deu &= dfs1(u, s);

	return deu;

}

void dfs2(ll v, ll pai){

	for (auto u : adj[v])
		dfs2(u, v);

	if (sum[v] == LLONG_MAX)
		for (auto u : adj[v])
			sum[v] = min(sum[u], sum[v]);

	if (adj[v].size() == 0 and sum[v] == LLONG_MAX)
		sum[v] = sum[pai];

}

ll dfs3(ll v){

	ll nf = adj[v].size();

	// dbg(v);	dbg(sum[v]);
	ll ret = sum[v];
	for (auto u : adj[v]){
		ret += dfs3(u);
	}

	return (ret - (nf*sum[v]));
}

int main(){
	fastio
	
	ll n;
	cin >> n;

	frr(i, n){
		if (i == 1) i++;
		ll x;
		cin >> x;

		adj[x].pb(i);
	}

	frr(i, n){
		ll x;
		cin >> x;

		sum[i] = x;
	}

	if(!dfs1(1, sum[1])){
		p(-1);
		return 0;
	}

	frr(i, n) if (sum[i] < 0) sum[i] = LLONG_MAX;

	dfs2(1, -1);

	// dbg(sum[2]);

	cout << dfs3(1) << endl; 
}
