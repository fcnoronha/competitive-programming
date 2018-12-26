// http://acm.timus.ru/problem.aspx?num=1671

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
	ll u, v;
} aresta;

#define maxn 100009

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
	fastio

	int n, m;
	cin >> n >> m;

	aresta mst[m];
	frr(i, n) id[i] = i, sz[i] = 1;

	fr(i, m) cin >> mst[i].u >> mst[i].v;

	int q; cin >> q;
	vector<bool> taoquei(m, true);
	vector<int> t;
	fr(i, q){
		int x; cin >> x;
		x--;
		t.pb(x);
		taoquei[x] = false;
	}

	ll ans = n;

	fr(i, m){
		if (taoquei[i] && find(mst[i].u) != find(mst[i].v)){
			ans--;
			join(mst[i].u, mst[i].v);
		}
	}

	vi anss;
	reverse(t.begin(), t.end());

	fr(i, t.size()){
		anss.pb(ans);
		if (find(mst[t[i]].u) != find(mst[t[i]].v)){
			ans--;
			join(mst[t[i]].u, mst[t[i]].v);
		}
	}

	reverse(anss.begin(), anss.end());
	fr(i, anss.size()){
		cout << anss[i];
		if (i < anss.size()-1) cout << " ";
		else cout << endl;
	}

}
