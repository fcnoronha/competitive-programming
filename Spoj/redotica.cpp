// https://br.spoj.com/problems/REDOTICA/

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
typedef long long int ll;

typedef struct{
	ll dis;
	ll u, v;
} aresta;

ll id[1009];
ll sz[1009];

bool comp(aresta a, aresta b){
	return a.dis < b.dis;
}

ll find(ll x){
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}

void join(ll p, ll q){
	p = find(p);
	q = find(q);
	
	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}


int main(){
	ll m, n;
	ll t = 1;

	ios::sync_with_stdio(false);

	while((cin >> n && n != 0) && cin >> m){

		aresta v[m+2];				

		fr(i, m){
			cin >> v[i].u >> v[i].v >> v[i].dis;
		}

		fr(i, n+4){
			id[i] = i;
			sz[i] = 1;
		}

		sort(v, v+m, comp);

		vector<aresta> mst;

		fr(i, m){
			if (find(v[i].u) != find(v[i].v)){
				join(v[i].u, v[i].v);
				mst.pb(v[i]);
			}
		}

		cout << "Teste " << t++ << endl;

		for (int i = 0; i < mst.size(); i++)
			cout << min(mst[i].u, mst[i].v) << " " << max(mst[i].v, mst[i].u) << endl;

		cout << endl;

		mst.clear();
	}
	return 0;
}
