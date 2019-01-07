// codcad.com/problem/204

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

#define MAXN 100009

ll seg[4*MAXN], lazy[4*MAXN];

void update(ll node, ll i, ll j, ll a, ll b, ll val){
	ll left = 2*node;
	ll right = 2*node+1;
	ll mid = (i+j)/2;

	if (lazy[node]){
		seg[node] = lazy[node]*(j-i+1);

		if (i != j)
			lazy[left] = lazy[right] = lazy[node];
		
		lazy[node] = 0;
	}

	if (i > j || i > b || a > j) return;

	if (a <= i && j <= b){

		seg[node] = val*(j-i+1);
		if (i != j)
			lazy[left] = lazy[right] = val;
	}

	else {
		update(left, i, mid, a, b, val);
		update(right, mid+1, j, a, b, val);
		seg[node] = seg[left] + seg[right];
	}
}

int query(ll node, ll i, ll j, ll a, ll b){
	ll left = 2*node;
	ll right = 2*node+1;
	ll mid = (i+j)/2;

	if (lazy[node]){
		seg[node] = lazy[node]*(j-i+1);

		if (i != j)
			lazy[left] = lazy[right] = lazy[node];
		
		lazy[node] = 0;
	}

	if (i > j || i > b || a > j) return 0;

	if (a <= i && j <= b)
		return seg[node];

	else {
		ll sum_l = query(left, i, mid, a, b);
		ll sum_r = query(right, mid+1, j, a, b);
		return sum_r + sum_l;
	}
}

int main(){
	fastio
	
	ll n, q;
	cin >> n >> q;

	frr(i, n){
		ll x;
		cin >> x;

		update(1, 1, n, i, i, x);
	}

	fr(i, q){
		ll o;
		cin >> o;
		o--;

		if (!o){
			ll a, b, k;
			cin >> a >> b >> k;

			update(1, 1, n, a, b, k);
		}

		else {
			ll a, b;
			cin >> a >> b;

			cout << query(1, 1, n, a, b) << endl;
		}
	}
}
