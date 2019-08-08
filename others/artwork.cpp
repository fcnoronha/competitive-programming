//open.kattis.com/problems/artwork

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int grid[1010][1010], id[2000009], sz[2000009], mp[1010][1010];
int n_reg, black_block;
int n, m, qs;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

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

	n_reg--;
}

void connect(int i, int j) {

	fr(h, 4) {

		int col = i+dx[h];
		int lin = j+dy[h];

		if (col < 1 || col > n || lin < 1 || lin > m) continue;
		if (grid[col][lin] > 0) continue;

		//cout << i << " " << j << " | " << col << " " << lin << endl;
		uni(mp[i][j], mp[col][lin]);
	}
}

int main(){
	fastio

	/*
	The idea is to solve the problem backwards. First we generate the grid as
	we read de queries. Then, after the 'artwork' is complete, I will join all
	adjacent white blocks (the grid is a union-find now). Now I just have to
	count the number of separated components and store it, and in each iteration
	I will undo some querie, store the answer for it, until there is no more
	queries. After all I just have to reverse the answer vector.

	I may have confused lin and col iterations.
	*/

	cin >> n >> m >> qs;

	pair< pii, pii > q[qs];

	// Reading queries and generating grid
	fr(i, qs) {

		cin >> q[i].f.f >> q[i].f.s;
		cin >> q[i].s.f >> q[i].s.s;

		for (int col = q[i].f.f; col <= q[i].s.f; col++)
			for (int lin = q[i].f.s; lin <= q[i].s.s; lin++)
				grid[col][lin]++;
	}

	// Why math?
	int cnt = 0;
	frr(i, n)
		frr(j, m)
			mp[i][j] = cnt++;

	// Initializing stuff
	n_reg = n*m;
	fr(i, cnt+10) id[i] = i, sz[i] = 1;

	// Setting up union-find
	frr(i, n) {
		frr(j, m) {

			if (grid[i][j] > 0) {

				black_block++;
				continue;
			}

			connect(i, j);
		}
	}

	vi ans;
	for (int i = qs-1; i >= 0; i--) {

		ans.pb(n_reg - black_block);

		for (int col = q[i].f.f; col <= q[i].s.f; col++)
			for (int lin = q[i].f.s; lin <= q[i].s.s; lin++) {
				grid[col][lin]--;

				if (grid[col][lin] == 0) {
					black_block--;
					connect(col, lin);
				}
			}
	}

	reverse(all(ans));
	pv(ans);
}
