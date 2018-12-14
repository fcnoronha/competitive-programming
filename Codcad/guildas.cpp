// http://www.codcad.com/problem/85

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


ll sz[100009], pt[100009], id[100009];

int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void join(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
	pt[q] += pt[p];
}

int main(){
	fastio
	 
	int m, n;
	while (cin >> n >> m && n != 0 && m != 0){
		int ans = 0;

		frr(i, n){
			id[i] = i;
			sz[i] = 1;

			int x;
			cin >> x;
			pt[i] = x;
		}

		fr(i, m){
			int q, a, b;
			cin >> q >> a >> b;

			if (q == 1){
				join(a, b);
			}

			else if (q == 2){
				if (find(1) == find(a))
					ans += (pt[find(a)] > pt[find(b)]);

				else if (find(1) == find(b))
					ans += (pt[find(b)] > pt[find(a)]);
			}
		}

		cout << ans << endl;
	}
}
