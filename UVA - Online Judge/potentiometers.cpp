// https://icpcarchive.ecs.baylor.edu/external/21/2191.pdf

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

#define MAXN 2000009

int bit[MAXN];

int query(int i){
	int s = 0;
	for (; i > 0; i -= i&-i)
		s += bit[i];
	return s;
}

void update(int x, int i){
	for (; i < MAXN; i += i&-i)
		bit[i] += x;
	return;
}

int main(){
	fastio

	int n, t = 0;
	while (cin >> n && n){
		
		if (t > 0) cout << endl;

		memset(bit, 0, (n+3) * sizeof(int));

		frr(i,n){
			int aux;
			cin >> aux;

			update(aux, i);
		}

		cout << "Case " << ++t << ":" << endl;

		string op;
		while (cin >> op && op != "END"){

			if (op == "S"){
				int x, r;
				cin >> x >> r;

				int aux = query(x) - query(x-1);
				update(r-aux, x);
			}

			else if (op == "M"){
				int l, r;
				cin >> l >> r;

				cout << query(r) - query(l-1) << endl;
			}
		}

	}
	return 0;
}
