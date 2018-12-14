// http://www.codcad.com/problem/63

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

int id[100005], sz[100005];

int find(int x){
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}

void join(int p, int q){
	q = find(q);
	p = find(p);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p,q);

	id[p] = q;
	sz[q] += sz[p];
}

int main(){
	int n, k;

	cin >> n >> k;

	frr(i, n)
		id[i] = i, sz[i] = 1;

	fr(i, k){
		char c;
		int a, b;

		cin >> c >> a >> b;
		if (c == 'C'){
			if (find(a) == find(b))
				cout << "S" << endl;
			else
				cout << "N" << endl;
		}
		else 
			join(a, b);
	}
}
