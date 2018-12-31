// www.codcad.com/problem/120

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

int grid[1009][1009], ans[1009][1009];
bool v[1009][1009];

void bfs(int i, int j, int t){
	if (i < 0 || i > 1000 || j < 0 || j > 1000) return;
	if (v[i][j]) return;

	v[i][j] = 1;
	if (grid[i][j] == 0) return;

	queue< pair<pii, int> > q;

	ans[i][j] = t;
	if (i+1 <= 1000) bfs(i+1, j, t+1);
	if (i-1 >= 0) bfs(i-1, j, t+1);
	if (j+1 <= 1000) bfs(i, j+1, t+1);
	if (j-1 >= 0) bfs(i, j-1, t+1);

	while (!q.empty()){

		pair<pii, int> aux = q.front();
		q.pop();

		pii cord = aux.f;
		int t = aux.s;

		int i = cord.f, j = cord.s;

		if (i < 0 || i > 1000 || j < 0 || j > 1000) return;
		if (v[i][j]) return;

		v[i][j] = 1;
		if (grid[i][j] == 0) return;
		ans[i][j] = t;

		if (i+1 <= 1000) q.push({{i+1, j}, t+1});
		if (i-1 >= 0) q.push({{i-1, j}, t+1});
		if (j+1 <= 1000) q.push({{i, j+1}, t+1});
		if (j-1 >= 0) q.push({{i, j-1}, t+1});

	}
}

int main(){
	fastio
	
	int n, m;
	cin >> n >> m;

	pii ini, fim;

	fr(i, n){ 
		fr(j, m){
			cin >> grid[i][j];

			if (grid[i][j] == 2){
				ans[i][j] = 1;
				ini = {i, j};
			}

			if (grid[i][j] == 3)
				fim = {i, j};
		}
	}

	queue< pair<pii, int> > q;
	q.push({{ini.f, ini.s}, 1});

	// BFS itself
	while (!q.empty()){

		pair<pii, int> aux = q.front();
		q.pop();

		pii cord = aux.f;
		int t = aux.s;

		int i = cord.f, j = cord.s;

		if (i < 0 || i > 1000 || j < 0 || j > 1000) continue;
		if (v[i][j]) continue;

		v[i][j] = 1;
		if (grid[i][j] == 0) continue	;
		ans[i][j] = t;

		if (i+1 <= 1000) q.push({{i+1, j}, t+1});
		if (i-1 >= 0) q.push({{i-1, j}, t+1});
		if (j+1 <= 1000) q.push({{i, j+1}, t+1});
		if (j-1 >= 0) q.push({{i, j-1}, t+1});

	}

	cout << ans[fim.f][fim.s] << endl;
}
