// https://codeforces.com/gym/100187/problem/J

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

int sz[200009],id[200009];

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
	int n; cin >> n;
	fr(i, n+3) id[i] = i, sz[i] = 1;

	int pos[n];

	fr(i, n){
		int x; cin >> x;
		pos[x] = i;
	}

	int k; cin >> k;

	fr(i, k){
		fr(j, n){
			int x; cin >> x;
			x--;
			uni(x, j);
		}
	}

	int fdp; cin >> fdp;
	fdp = pos[fdp];

	if (find(fdp) == find(0)) cout << "YES" << endl;
	else cout << "NO" << endl;
}
