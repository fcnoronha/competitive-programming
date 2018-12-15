// https://codeforces.com/contest/1093/problem/G

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll val[300009];

ll treemx[1200009], treemn[1200009];
ll rg[1200009], lf[1200009];

void build(ll node, ll bleft, ll bright){
	rg[node] = bright;
	lf[node] = bleft;

	if (bleft == bright)
		treemx[node] = treemn[node] = val[bright];

	else{
		ll mid = (bleft+bright)/2ll;

		build(2ll*node, bleft, mid);
		build(2ll*node+1ll, mid+1ll, bright);

		treemx[node] = max(treemx[2ll*node], treemx[2ll*node+1ll]);
		treemn[node] = min(treemn[2ll*node], treemn[2ll*node+1ll]);
	}
}

ll querymx(ll node, ll qleft, ll qright){
	if (rg[node] < qleft || qright < lf[node]) return -90000000ll;

	if (lf[node] >= qleft && rg[node] <= qright) return treemx[node];

	return max(querymx(2ll*node, qleft, qright), querymx(2ll*node+1ll, qleft, qright));
}

ll querymn(ll node, ll qleft, ll qright){
	if (rg[node] < qleft || qright < lf[node]) return 90000000ll;

	if (lf[node] >= qleft && rg[node] <= qright) return treemn[node];

	return min(querymn(2ll*node, qleft, qright), querymn(2ll*node+1ll, qleft, qright));
}

void update(ll index, ll left, ll right, ll index_updt, ll value){
	if (left == right){
		treemx[index] = treemn[index] = value;
	}
	else {
		ll mid = (left+right)/2ll;

		if (index_updt <= mid)
			update(2ll*index, left, mid, index_updt, value);

		else
			update(2ll*index+1ll, mid+1ll, right, index_updt, value);

		treemx[index] = max(treemx[2ll*index], treemx[2ll*index+1ll]);
		treemn[index] = min(treemn[2ll*index], treemn[2ll*index+1ll	]);
	}
}

int main(){
	fastio

	ll n, k;
	cin >> n >> k;

	frr(i, n){
		ll aux = 0ll;
		fr(i, k){
			ll a;
			cin >> a;
			aux += a;
		}
		val[i] = aux;
	}

	build(1ll, 1ll, n);

	ll q;
	cin >> q;
	while (q--){
		int o;
		cin >> o;
		o--;

		if (!o){

			ll i, aux = 0ll, a;
			cin >> i;
			fr(i, k)
				cin >> a, aux += a;

			update(1ll, 1ll, n, i, aux);
		}

		else {

			ll l, r;
			cin >> l >> r;

			ll ans = max(abs(querymx(1ll, l, r) - querymn(1ll, l, r)),
				abs(querymn(1ll, l, r) - querymx(1ll, l, r)));

			cout << ans << endl;
		}
	}
}
