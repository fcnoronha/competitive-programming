// codeforces.com/contest/375/problem/D

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

typedef struct {
	int l, r, i, k;
} query;

int bit[2*MAXN];
pii lim[MAXN];
vi adj[MAXN];
int color[MAXN]; // Color of each vertex
int freq[MAXN]; // Amount of vertices that i-th color has
query q[MAXN]; // Queries
int cnt = 1; // Used for DFS
int n, m; // Number of vertices and number of queries
bool vis[MAXN];
int vans[MAXN];
int bsz;
int col[2*MAXN];

void dfs(int v){
	// Transform tree in a vector
	if (vis[v]) return;
	vis[v] = 1;

	lim[v].f = cnt++;

	for (auto u : adj[v]){
		if (vis[u]) continue;
		dfs(u);
		cnt++;
	}

	lim[v].s = cnt;
}

bool comp(query a, query b){

	if (a.l/bsz != b.l/bsz)
		return a.l/bsz < b.l/bsz;

	return a.r < b.r;
}

void mos(){

	bsz = static_cast<int>(floor(sqrt(n)));

	sort(q, q+m, comp);

	int cr = 0, cl = 0;

	for (int i = 0; i < m; i++){

		int l = q[i].l;
		int r = q[i].r;

		while (cl < l){
			if (freq[col[cl]] <= 0){
				freq[col[cl]]--;
				cl++;
				continue;
			}

			bit[freq[col[cl]]]--;
			freq[col[cl]]--;
			cl++;
		}

		while (cl > l){
			cl--;

			freq[col[cl]]++;
			bit[freq[col[cl]]]++;
		}

		while (cr < r){
			++cr;
			
			freq[col[cr]]++;
			bit[freq[col[cr]]]++;
		}

		while (cr > r){
			if (freq[col[cr]] <= 0){
				freq[col[cr]]--;
				cr--;
				continue;
			}

			bit[freq[col[cr]]]--;
			freq[col[cr]]--;

			cr--;
		}

		vans[q[i].i] = bit[q[i].k+q[i].k];
	}
}

int main(){
	fastio
	
	cin >> n >> m;
	frr(i, n) cin >> color[i];

	fr(i, n-1){
		int u, v;
		cin >> u >> v;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	
	frr(i, n)
		col[lim[i].f] = col[lim[i].s] = color[i];

	fr(i, m){
		int v, k;
		cin >> v >> k;

		q[i].l = lim[v].f;
		q[i].r = lim[v].s;
		q[i].i = i;
		q[i].k = k;
 	}

 	mos();

 	fr(i, m) cout << vans[i] << endl;
 	// fr(i, 3*MAXN) if (bitq(i)) dbg((i));
}
