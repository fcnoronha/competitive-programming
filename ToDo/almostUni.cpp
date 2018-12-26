// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3138

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

#define maxn 200009

ll id[maxn], sz[maxn], sum[maxn];

ll find(ll x){
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}

void join(ll p, ll q){
	p = find(p);
	q = find(q);
	
	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	sum[q] += sum[p];
	id[p] = q;
	sz[q] += sz[p];
}

int main(){
	fastio

	int n, m;
	while (scanf("%d %d", &n, &m) != EOF){

		ll map[n+m+9];

		frr(i, n){
			id[i] = i;
			sz[i] = 1;
			sum[i] = i;
			map[i] = i;
		}

		ll trans = n+2;
		fr(i, m){

			int o; cin >> o;

			if (o == 1){
				ll p, q;
				cin >> p >> q;
				p = map[p];
				q = map[q];

				join(p, q);
			}

			else if (o == 2){
				ll p, q;
				cin >> p >> q;

				ll po = p;
				p = map[p];
				q = map[q];

				ll aux = find(p);
				sz[aux]--;
				sum[aux] -= po;

				map[po] = trans;
				sz[trans] = 1;
				id[trans] = trans;
				sum[trans] = po;

				join(trans, q);
				trans++;
 			}

			else {
				ll p; 
				cin >> p;
				// dbg(map[p]);
				p = map[p];
				// dbg(find(p));
				p = find(p);
				cout << sz[p] << " " << sum[p] << endl;
			}
		}
	}

	return 0;
}
