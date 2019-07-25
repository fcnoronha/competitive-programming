//codeforces.com/contest/438/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n, m;
ll *sum = new ll[500009];
ll *max_val = new ll[500009];

void update(int node, int i, int j, int idx, ll val){

	if (i == j){
		sum[node] = val;
		max_val[node] = val;
        return;
	}

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	if (idx <= mid) update(left, i, mid, idx, val);
	else            update(right, mid+1, j, idx, val);

    sum[node] = sum[right] + sum[left];
	max_val[node] = max(max_val[right], max_val[left]);
}

ll query_sum(int node, int i, int j, int a, int b){

	if (a <= i && j <= b)
		return sum[node];

	if (i > b || a > j)
		return 0ll;

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	ll ansl = query_sum(left, i, mid, a, b);
	ll ansr = query_sum(right, mid+1, j, a, b);

	return ansl + ansr;
}

void query_mod(int node, int i, int j, int a, int b, ll x){

    if (i > b || a > j || max_val[node] < x)
        return;

	if (i == j){
        sum[node] = max_val[node] = sum[node]%x;
        return;
    }

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	query_mod(left, i, mid, a, b, x);
	query_mod(right, mid+1, j, a, b, x);

    sum[node] = sum[right] + sum[left];
	max_val[node] = max(max_val[right], max_val[left]);
}

int main(){
    fastio

    cin >> n >> m;

    ll aux;
    fr(i, n) {
        cin >> aux;
        update(1, 0, n-1, i, aux);
    }

    while (m--) {

        int t;
        cin >> t;

        if (t == 1) {
            int l, r;
            cin >> l >> r;

            cout << query_sum(1, 0, n-1, --l, --r) << "\n";
        }

        if (t == 2) {

            int l, r;
            ll x;
            cin >> l >> r >> x;

            query_mod(1, 0, n-1, --l, --r, x);
        }

        if (t == 3) {

            int k;
            ll x;
            cin >> k >> x;

            update(1, 0, n-1, --k, x);
        }
    }
}
