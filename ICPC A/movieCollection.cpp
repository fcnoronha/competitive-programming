// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3913

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define MAXN 300009
vi bit(MAXN);

int query(int i){
	int s = 0;
	for (; i > 0; i -= i&-i)
		s += bit[i];
	return s;
}

void update(int i, int x){
	for (; i < MAXN; i += i&-i)
		bit[i] += x;
}

int main(){
	int t;
	cin  >> t;

	while (t--){

		int m, r;
		cin >> m >> r;

		fill(bit.begin(), bit.end(), 0);
		vi pos(m+6, 0);
		frr(i, m){
			update(r+i, 1);
			pos[i] = r+i;
		}

		for (int i = r; i > 0; i--){

			int a;
			cin >> a;

			cout << query(pos[a]) - 1;
			if (i > 1) cout << " ";

			update(pos[a], -1);
			pos[a] = i;
			update(pos[a], 1);
		}
		
		cout << endl;
	}
}
