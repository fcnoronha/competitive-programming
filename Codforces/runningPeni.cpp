// codeforces.com/gym/101879/problem/G

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

pii seg[4*MAXN], val[MAXN];

// pair : esquerda, direita

void update(int node, int i, int j, int idx, pii v){

	if (i == j){
		seg[node] = v;
		val[idx] = v; 
	}

	else {
		int left = 2*node;
		int right = 2*node + 1;
		int mid = (i+j)/2;

		if (idx <= mid) update(left, i, mid, idx, v);
		else 			update(right, mid+1, j, idx, v);

		pii a = seg[left];
		pii b = seg[right];

		if (a.s < b.f || b.s < a.f)
			seg[node] = {INT_MAX, INT_MIN};

		else{
			seg[node].f = max(a.f, b.f);
			seg[node].s = min(a.s, b.s);
		}
	}
}

pii query(int node, int i, int j, int a, int b){

	if (a <= i && j <= b){
		//dbg(seg[node].f);
		return seg[node];
	}

	if (i > b || a > j){
		// p(to aq 1);
		return {INT_MIN, INT_MAX};
	}

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	pii ax = query(left, i, mid, a, b);
	pii bx = query(right, mid+1, j, a, b);

	if (ax.s < bx.f || bx.s < ax.f)
		return {INT_MAX, INT_MIN	};

	else
		return {max(ax.f, bx.f), min(ax.s, bx.s)};
	
}

int main(){
	fastio
	
	int n, q;
	cin >> n >> q;

	int l, r, idx;
	frr(i, n){
		cin >> l >> r;

		update(1, 1, n, i, {l, r});
	}

	char op;
	fr(i, q){
		cin >> op;

		if (op == 'C'){
			// update

			cin >> idx >> l >> r;	
			update(1, 1, n, idx, {l, r});
		}

		else {
			// query

			cin >> l >> r;

			pii aux = query(1, 1, n, l, r);
			// dbg(aux.f);

			if (aux.f == INT_MAX || aux.f == INT_MIN)
				cout << 0 << endl;

			else 
				cout << (aux.s - aux.f + 1) << endl; 
		}
	}
}
