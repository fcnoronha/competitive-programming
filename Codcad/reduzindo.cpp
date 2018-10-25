// http://www.codcad.com/problem/125

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

ll n, m, sz[600], id[600];

typedef struct aresta{
	ll u;
	ll v;
	ll c;
} aresta;

bool comp(aresta a, aresta b){
	return a.c < b.c;
}

ll find(ll x){
	if (x == id[x]) return x;
	return id[x] = find(id[x]);
}

void uni(ll a, ll b){
	a = find(a);
	b = find(b);

	if(a == b) return;
	if(sz[b] > sz[a]) swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
}

int main(){
	

	cin >> n >> m;

	aresta con[m+3];

	fr (i, m){
		cin >> con[i].u >> con[i].v >> con[i].c;
	}

	sort(con, con+m, comp);
	fr(i, n) id[i] = i, sz[i] = 1;

	ll ans = 0;

	fr(i, m){
		if (find(con[i].u) != find(con[i].v)){
			ans += con[i].c;
			uni(con[i].u, con[i].v);
		}
	}

	cout << ans << endl;
}
