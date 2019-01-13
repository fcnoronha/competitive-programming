// www.urionlinejudge.com.br/judge/en/problems/view/2658

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

pii seg[4*MAXN];

void update(int node, int i, int j, int idx, pii val){

	if (i == j){
		seg[node] = val;
		return;
	}

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	if (idx <= mid) update(left, i, mid, idx, val);
	else 			 update(right, mid+1, j, idx, val);

	seg[node].f = max(seg[left].f, seg[right].f);
	seg[node].s = min(seg[left].f, seg[right].f);
	int aux = max(seg[left].s, seg[right].s);
	seg[node].s = max(seg[node].s, aux);
}

pii query(int node, int i, int j, int a, int b){

	if (a <= i && j <= b) 
		return seg[node];

	if (i > b || a > j) 
		return {INT_MIN, INT_MIN};

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	pii ansl = query(left, i, mid, a, b);
	pii ansr = query(right, mid+1, j, a, b);

	pii ans;
	ans.f = max(ansl.f, ansr.f);
	ans.s = min(ansl.f, ansr.f);

	int aux = max(ansl.s, ansr.s);
	ans.s = max(ans.s, aux);

	return ans;
}

int main(){
	fastio
	
	int n;
	cin >> n;

	int x;
	frr(i, n){
		cin >> x;

		update(1, 1, n, i, {x, INT_MIN});
	}

	int q, a, b;
	char op;
	cin >> q;

	while (q--){

		cin >> op >> a >> b;

		if (op == 'U'){

			update(1, 1, n, a, {b, INT_MIN});

		}

		else {

			pii aux = query(1, 1, n, a, b);

			cout << aux.f+aux.s << endl;

		}

	}
}
