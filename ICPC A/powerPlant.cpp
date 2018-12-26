// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4448

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

typedef struct{
	ll d, u, v;
} aresta;

bool comp(aresta a, aresta b){
	return a.d < b.d;
}

#define maxn 209

int id[maxn], sz[maxn];

int find(int x){
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);

	if (sz[a] < sz[b]) id[a] = b;
	else if (sz[b] < sz[a]) id[b] = a;
	else {
		id[a] = b;
		sz[b] ++;
	}
}

int main(){
	int t, c = 1; cin >> t;
	while (t--){
		int n, m, k;
		cin >> n >> m >> k;

		aresta mst[m];
		frr(i, n) id[i] = i, sz[i] = 1;

		int ant, x;
		fr(i, k){
			if (i == 0) cin >> ant;
			else{
				cin >> x;
				join(x, ant);
			}
		}

		fr(i, m) cin >> mst[i].u >> mst[i].v >> mst[i].d;

		sort(mst, mst+m, comp);
		ll ans = 0;

		fr(i, m){
			if (find(mst[i].u) != find(mst[i].v)){
				join(mst[i].u, mst[i].v);
				ans += mst[i].d;
			}
		}

		printf("Case #%d: %lld\n", c++, ans);
	}
	return 0;
}
