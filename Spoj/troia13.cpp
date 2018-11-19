// https://br.spoj.com/problems/TROIA13/

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


int id[50010], sz[50010];

int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}

int main(){
	int n, m;

	cin >> n >> m;

	frr(i, n)
		id[i] = i, sz[i] = 1;

	fr(i, m){
		int x,y;
		cin >> x >> y;
		uni(x, y);
	}

	vector<int> v(n+2, 0);

	frr(i, n)
		v[find(i)]++;

	int ans = 0;
	fr(i, v.size())
		if(v[i] > 0) ans++;

	cout << ans << endl;
}
