//codeforces.com/contest/1064/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int grid[2009][2009];
int visited[2009][2009];
pii amtp[2009][2009];

int main(){
	fastio

	int n, m;
	cin >> n >> m;

	int r, c;
	cin >> r >> c;

	int x, y;
	cin >> x >> y; // x - leftmoves, r - right moves

	string str;
	frr(i, n){

		cin >> str;
		fr(j, m)
			if (str[j] == '*')
				grid[i][j+1] = -1;
	}

	frr(i, n) frr(j, m) amtp[i][j] = {0, 0};

	queue<pair<pii, pii>> q;
	q.push({{r,c}, {x, y}});

	while (!q.empty()){

		pii dir = q.front().f;
		pii amt = q.front().s;
		q.pop();

		if (!(amt.f > amtp[dir.f][dir.s].f || amt.s > amtp[dir.f][dir.s].s)) continue;

		if (grid[dir.f][dir.s] < 0) continue;
		grid[dir.f][dir.s] = 1;

		pii aux = amtp[dir.f][dir.s];
		amtp[dir.f][dir.s].f = max(amt.f, amtp[dir.f][dir.s].f);
		amtp[dir.f][dir.s].s = max(amt.s, amtp[dir.f][dir.s].s);

		if (dir.f-1 > 0 && (amt.f > amtp[dir.f-1][dir.s].f || amt.s > amtp[dir.f-1][dir.s].s) && grid[dir.f-1][dir.s] != -1) 
			q.push({{dir.f-1, dir.s}, {amt.f, amt.s}});

		if (dir.f+1 <= n  && (amt.f > amtp[dir.f+1][dir.s].f || amt.s > amtp[dir.f+1][dir.s].s)&& grid[dir.f+1][dir.s] != -1) 
			q.push({{dir.f+1, dir.s}, {amt.f, amt.s}});

		if (dir.s-1 > 0 && (amt.f > amtp[dir.f][dir.s-1].f || amt.s > amtp[dir.f][dir.s-1].s) && amt.f > 0 && grid[dir.f][dir.s-1] != -1) 
			q.push({{dir.f, dir.s-1}, {amt.f-1, amt.s}});

		if (dir.s+1 <= m && (amt.f > amtp[dir.f][dir.s+1].f || amt.s > amtp[dir.f][dir.s+1].s) && amt.s > 0 && grid[dir.f][dir.s+1] != -1) 
			q.push({{dir.f, dir.s+1}, {amt.f, amt.s-1}});

		/*
		amt = aux;
		if (dir.f-1 > 0 && (amt.f > amtp[dir.f-1][dir.s].f || amt.s > amtp[dir.f-1][dir.s].s || !visited[dir.f-1][dir.s])) 
			q.push({{dir.f-1, dir.s}, {amt.f, amt.s}});

		if (dir.f+1 <= n  && (amt.f > amtp[dir.f+1][dir.s].f || amt.s > amtp[dir.f+1][dir.s].s || !visited[dir.f+1][dir.s])) 
			q.push({{dir.f+1, dir.s}, {amt.f, amt.s}});

		if (dir.s-1 > 0 && (amt.f > amtp[dir.f][dir.s-1].f || amt.s > amtp[dir.f][dir.s-1].s) && amt.f > 0) 
			q.push({{dir.f, dir.s-1}, {amt.f-1, amt.s}});

		if (dir.s+1 <= m && (amt.f > amtp[dir.f][dir.s+1].f || amt.s > amtp[dir.f][dir.s+1].s) && amt.s > 0) 
			q.push({{dir.f, dir.s+1}, {amt.f, amt.s-1}});
		*/
	}

	q.push({{r,c}, {x, y}});

	while (!q.empty()){

		pii dir = q.front().f;
		pii amt = q.front().s;

		q.pop();
		if (visited[dir.f][dir.s]) continue;
		visited[dir.f][dir.s] = true;

		if (grid[dir.f][dir.s] < 0) continue;
		grid[dir.f][dir.s] = 1;

		if (dir.f-1 > 0 && !visited[dir.f-1][dir.s]) q.push({{dir.f-1, dir.s}, {amt.f, amt.s}});
		if (dir.f+1 <= n  && !visited[dir.f+1][dir.s]) q.push({{dir.f+1, dir.s}, {amt.f, amt.s}});

		if (dir.s-1 > 0 && !visited[dir.f][dir.s-1] && amt.f > 0) 
			q.push({{dir.f, dir.s-1}, {amt.f-1, amt.s}});

		if (dir.s+1 <= m && !visited[dir.f][dir.s+1] && amt.s > 0) 
			q.push({{dir.f, dir.s+1}, {amt.f, amt.s-1}});
	}

	int ans = 0;
	frr(i, n) frr(j, m) ans += (grid[i][j] == 1);

	cout << ans << endl;
}
