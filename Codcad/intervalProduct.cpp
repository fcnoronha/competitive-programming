// codcad.com/problem/159

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
ll bit[MAXN][3];
ll val[MAXN];

ll query(int i, int p){
	ll ans = 0;
	for(; i > 0; i -= i&-i) 
		ans += bit[i][p];
	return ans;
}

void update(int i, ll v, int p){
	for (; i < MAXN; i += i&-i)
		bit[i][p] += v; 
}

int main(){
	fastio
	
	int n, k;
	while (cin >> n >> k && n != EOF){

		fr(i, n+3) fr(j, 3) bit[i][j] = 0;

		frr(i, n){
			cin >> val[i];

			if (val[i] == 0) update(i, 1, 0);
			if (val[i] > 0) update(i, 1, 1);
			if (val[i] < 0) update(i, 1, 2);
		}

		fr(i, k){
			char op;
			cin >> op;

			if (op == 'C'){
				ll v;
				int x;
				cin >> x >> v;

				int p = 0;
				p = (val[x] > 0)*1 + (val[x] < 0)*2;
				update(x, -1, p);

				if (v == 0) p = 0;
				if (v > 0) p = 1;
				if (v < 0) p = 2;

				update(x, 1, p); 
				val[x] = v;
			}	

			else {
				int a, b;
				cin >> a >> b;

				ll aux = query(b, 0) - query(a-1, 0);
				if (aux > 0){
					cout << "0";
					continue;
				}

				aux = query(b, 2) - query(a-1, 2);
				if (aux%2 == 0){
					cout << "+";
					continue;
				}

				cout << "-";
			}
		}

		cout << endl;
	}
}
