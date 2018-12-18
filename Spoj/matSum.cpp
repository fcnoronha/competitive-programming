// https://www.spoj.com/problems/MATSUM/

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

#define MAXN 1030
ll bit[MAXN][MAXN], n;

ll sum(ll x, ll y){
	ll ans = 0;
	for (ll i = x; i > 0; i -= i&-i)
		for (ll j = y; j > 0; j -= j&-j)
			ans += bit[i][j];
	return ans;
}

void update(ll x, ll y, ll v){
	for (ll i = x; i < n+2; i += i&-i)
		for (ll j = y; j < n+2; j += j&-j)
			bit[i][j] += v;
}

int main(){
	fastio

	ll t;
	cin >> t;
	while (t--){

		cin >> n;

		memset(bit, 0, sizeof(bit));
		//fr(i, n+3) fr(j, n+3) bit[i][j] = 0;

		string op;
		while (cin >> op && op != "END"){

			if (op == "SET"){
				ll x, y, v;
				cin >> x >> y >> v;
				x++; y++;

				ll aux = sum(x, y) - sum(x-1,y) - sum(x, y-1) + sum(x-1,y-1);
				update(x, y, v-aux);
			}

			else {
				ll x1,y1,x2,y2;
				cin >> x1 >> y1 >> x2 >> y2;
				x1++; x2++; y1++; y2++;


				ll ans = sum(x2,y2) - sum(x2, y1-1) - sum(x1-1, y2)
					+ sum(x1-1,y1-1);

				cout << ans << endl;
			}

		}
		
		cout << endl;

	}
	return 0;
}
