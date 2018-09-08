// https://www.spoj.com/problems/RPLN/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

ll val[100009];
ll tree[400009];
ll rg[400009], lf[400009];

void build(int node, int bleft, int bright){
	rg[node] = bright;
	lf[node] = bleft;

	if (bleft == bright)
		tree[node] = val[bright];

	else{
		int mid = (bleft+bright)/2;

		build(2*node, bleft, mid);
		build(2*node+1, mid+1, bright);

		tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

ll query(int node, int qleft, int qright){
	if (rg[node] < qleft || qright < lf[node]) return LLONG_MAX;

	if (lf[node] >= qleft && rg[node] <= qright) return tree[node];

	return min(query(2*node, qleft, qright), query(2*node+1, qleft, qright));
}


int main(){
	int t;
	cin >> t;

	frr(i, t){
		int n, q;
		cin >> n >> q; 
		fr(i, n) cin >> val[i];

		fill(tree, tree+(n*4), LLONG_MAX);
		build(1, 0, n-1);

		cout << "Scenario #" << i << ":" << endl;
		while(q--){
			int a, b;
			cin >> a >> b;
			cout << query(1, a-1, b-1) << endl;
		}
	}
}