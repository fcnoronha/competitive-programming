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

#define maxn 100009

ll seg[maxn<<1];
int n, q;

void build() {
	for (int i = n-1; i > 0; i--)
		seg[i] = min(seg[i<<1], seg[i<<1|1]);
}

ll query(int l, int r) {
	ll ans = INT_MAX;
	for (l += n, r += n; l<r; l >>= 1, r >>= 1) {
		if (l&1) ans = min(ans, seg[l++]);
		if (r&1) ans = min(ans, seg[--r]); 
	}
	return ans;
}

int main(){
	int t;
	cin >> t;

	frr(i, t){
		cin >> n >> q; 
		fr(i, n) cin >> seg[i+n];

		build();

		cout << "Scenario #" << i << ":" << endl;
		while(q--){
			int a, b;
			cin >> a >> b;
			cout << query(a-1, b) << endl;
		}
	}
}