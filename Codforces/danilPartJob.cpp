// codeforces.com/contest/877/problem/E

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

#define MAXN 200009

int state[MAXN];
vi adj[MAXN];
pii limits[MAXN];
bool visited[MAXN];
int cnt = 1;

void dfs(int u){

	limits[u].f = cnt++;

	for (auto child : adj[u]){

		if (visited[child]) continue;
		visited[child] = 1;

		dfs(child);
	}

	limits[u].s = cnt;
}

int lazy[4*MAXN];
pii seg[4*MAXN];

void update(int node, int i, int j, int a, int b){
	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	if (lazy[node]){

		swap(seg[node].f, seg[node].s);

		if (i != j){
			lazy[left] = !lazy[left];
			lazy[right] = !lazy[right];
		}

		lazy[node] = 0;
	}

	if (i > j || i > b || a > j) return;

	if (a <= i && j <= b){

		if (!seg[node].f && !seg[node].s)
			seg[node].s = 1;

		else 
			swap(seg[node].f, seg[node].s);

		if (i != j){
			lazy[left] = !lazy[left];
			lazy[right] = !lazy[right];
		}
	}

	else {
		update(left, i, mid, a, b);
		update(right, mid+1, j, a, b);
		seg[node].f = seg[left].f + seg[right].f;
		seg[node].s = seg[left].s + seg[right].s;
	}
}

int query(int node, int i, int j, int a, int b){
	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	if (lazy[node]){
		swap(seg[node].f, seg[node].s);
		
		if (i != j){
			lazy[left] = !lazy[left];
			lazy[right] = !lazy[right];
		}
		lazy[node] = 0;
	}

	if (i > j || i > b || a > j) return 0;

	if (a <= i && j <= b)
		return seg[node].f;

	else {
		int sum_l = query(left, i, mid, a, b);
		int sum_r = query(right, mid+1, j, a, b);
		return sum_r + sum_l;
	}
}


int main(){
	fastio
	
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++){
		int x;
		cin >> x;

		adj[x].pb(i);
		adj[i].pb(x);
	}

	visited[1] = 1;
	dfs(1);

	frr(i, n){
		update(1, 1, cnt, limits[i].f, limits[i].f);
		cin >> state[i];

		if (state[i] > 0){
			// dbg(i);
			update(1, 1, cnt, limits[i].f, limits[i].f);
		}
	}

	int q;
	cin >> q;

	string op;
	int v;
	while (q--){
		int aux = query(1, 1, cnt, limits[6].f, limits[6].s-1);

		cin >> op >> v;

		if (op[0] == 'g'){

			int ans = query(1, 1, cnt, limits[v].f, limits[v].s-1);

			cout << ans << endl;
		}

		else {
			
			update(1, 1, cnt, limits[v].f, limits[v].s-1);

		}
	}
}
