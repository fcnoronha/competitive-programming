// https://codeforces.com/contest/1095/problem/D

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

int main(){
	fastio
	
	int n; cin >> n;

	pii ord[n];
	fr(i, n) cin >> ord[i].f >> ord[i].s, ord[i].f--, ord[i].s--;

	vi ans;
	ans.pb(ord[0].f);
	ans.pb(ord[0].s);

	vector<bool> v(n, false);
	vector<bool> u(n, false);

	v[0] = true;
	u[ord[0].f] = true;
	u[ord[0].s] = true;

	while(ans.size() < n){
		int i = ans.size();
		i -= 2;

		//if (v[ans[i]]) i = 0;
		if (i < ans.size() && v[ans[i]]) i++;
		v[ans[i]] = true;

		int f = ord[ans[i]].f, s = ord[ans[i]].s; 

		if (i+1 < ans.size() && ans[i+1] == f && !u[s]){
			ans.pb(s);
			u[s] = true;
			continue;
		}

		if (i+1 < ans.size() && ans[i+1] == s && !u[f]){
			ans.pb(f); 
			u[s] = true;
			continue;
		}

		if (i+1 < ans.size()) swap(ans[i], ans[i+1]);

		if (!u[f]){
			u[f] = true;
			ans.pb(f);
		}

		if (!u[s]){
			u[s] = true;
			ans.pb(s);
		}
	}

	for (auto u : ans) cout << u+1 << " ";
	cout << endl;
}

/*

6
5 6 
1 4
2 4
6 1 
2 3
3 5

RODA AI

*/