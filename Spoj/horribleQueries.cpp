// www.spoj.com/problems/HORRIBLE/

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

#define MAXN 100009
ll lazy[4*MAXN], seg[4*MAXN];

void update(int node, int i, int j, int a, int b, ll val){
	int left = 2*node;
	int right = 2*node+1;
	int mid = (i+j)/2;

	if (lazy[node]){

		seg[node] += lazy[node]*(j-i+1);

		if (i != j){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}

		lazy[node] = 0;
	}

	if (i > j || i > b || a > j) return;

	if (a <= i && j <= b){

		seg[node] += val*(j-i+1);

		if (i != j){
			lazy[right] += val;
			lazy[left] += val;
		}
	}

	else {
		update(left, i, mid, a, b, val);
		update(right, mid+1, j, a, b, val);

		seg[node] = seg[left] + seg[right];
	}
}

ll query(int node, int i, int j, int a, int b){
	int left = 2*node;
	int right = 2*node+1;
	int mid = (i+j)/2;

	if (lazy[node]){

		seg[node] += lazy[node]*(j-i+1);

		if (i != j){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}

		lazy[node] = 0;	
	}

	if (i > j || i > b || a > j) return 0ll;

	if (a <= i && j <= b)
		return seg[node];

	else {
		return query(left, i, mid, a, b) + query(right, mid+1, j, a, b);
	}

} 


int main(){
	fastio
	
	int t;
	cin >> t;

	while (t--){

		int n, c;
		cin >> n >> c;
		memset(seg, 0ll, sizeof(seg));
		memset(lazy, 0, sizeof(seg));

		while (c--){

			int op;
			cin >> op;

			if (op){
				// query
				int p, q;
				cin >> p >> q;

				cout << query(1, 1, n, p, q) << endl;
			}

			else {
				// update
				int p, q;
				ll v;
				cin >> p >> q >> v;

				update(1, 1, n, p, q, v);
			}
		}
	}
}