//codeforces.com/contest/1106/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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

bool vis[100009];
vi adj[100009];

vi ans;
set<int> aux;
int n, m;

void fb(int v){

	if (ans.size() == n || vis[v]){
		aux.erase(v);
		return;
	}

	sort(all(adj[v]));

	if (v == *(aux.begin()) && !vis[v]){
		ans.pb(v);
		vis[v] = 1;
		aux.erase(v);
	}

	for (auto u : adj[v]){
		if (vis[u]) continue;
		aux.insert(u);
	}

	for (auto u : adj[v]){
		if (vis[u]) continue;
		if (u <= *(aux.begin())) 
			fb(u);
	}
}

int main(){
	fastio
	
	cin >> n >> m;

	fr(i, m){

		int u, v;
		cin >> u >> v;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	aux.insert(1);

	while (!aux.empty())
		fb(*(aux.begin()));

	pv(ans);
}



	
	
	
	
	
	
	
	
	
	
	

