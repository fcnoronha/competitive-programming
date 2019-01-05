//codeforces.com/contest/1068/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

vi grid[109];

int main(){
	fastio
	
	int n, m;
	cin >> n >> m;

	frr(i, n) grid[i].pb(i);

	int x = n+1;

	fr(i, m){
		int u, v;
		cin >> u >> v;

		grid[u].pb(x);
		grid[v].pb(x);
		x++;
	}

	frr(i, n){

		cout << grid[i].size() << endl;

		fr(j, grid[i].size())
			cout << grid[i][j] << " " << i << endl;
	}
}
