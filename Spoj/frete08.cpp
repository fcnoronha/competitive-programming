// https://br.spoj.com/problems/FRETE08

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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


typedef struct{
	int v,u,dis;
} aresta;

bool comp(aresta a, aresta b){
	return a.dis < b.dis;
}

int id[1003], sz[1003];

int find(int x){
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}

void join(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}

int main(){
	int n, m, ans = 0;

	cin >> n >> m;

	aresta v[m];

	fr(i, m)
		cin >> v[i].u >> v[i].v >> v[i].dis;

	sort(v, v+m, comp);

	frr(i, n)
		id[i] = i, sz[i] = 1;

	vector<aresta> mst;

	fr(i, m){
		if (find(v[i].u) != find(v[i].v)){
			join(v[i].u, v[i].v);
			mst.pb(v[i]);
		}
	}

	for (aresta i : mst)
		ans += i.dis;

	cout << ans << endl;
}
