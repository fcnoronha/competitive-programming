// codeforces.com/contest/512/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

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
typedef long double ld;

vi adj[27];
int seg[27], prv[27], dgr[27];
int cnt;

void dfs(int v){

	if (dgr[v] > 0 || prv[v] != -1)
		return;

	prv[v] = cnt;
	seg[cnt++] = v;

	for (auto u : adj[v]){
		dgr[u]--;
		dfs(u);
	}
}

int main(){
	fastio

	int n;
	cin >> n;

	string name[n];
	fr(i, n) cin >> name[i];

	ms(seg, -1);
	ms(prv, -1);
	ms(dgr, 0);

	bool taoquei = 1;
	frr(i, n-1){

		int act = 0;
		while (act < min(name[i].length(), name[i-1].length()) \
			&& name[i][act] == name[i-1][act])
				act++;

		if (act == name[i-1].length())
			continue;

		if (act == name[i].length()){
			// Case that pretests dont get

			taoquei = 0;
			break;
		}

		int u = name[i-1][act] - 'a';
		int v = name[i][act] - 'a';
		adj[u].pb(v);
		dgr[v]++;
	}

	fr(i, 26)
		dfs(i);

	taoquei &= (cnt == 26);

	if (taoquei){
		fr(i, 26)
			cout << (char)(seg[i] + 'a');
		cout << endl;
		return 0;
	}

	cout << "Impossible" << endl;
}
