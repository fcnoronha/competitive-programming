// codeforces.com/contest/988/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

int main(){
	fastio
	
	int k;
	cin >> k;

	vi memo[k];
	vi nis;
	vl sum;

	fr(i, k){
		int n;
		cin >> n;
		nis.pb(n);

		ll aux, sm = 0;
		fr(j, n){
			cin >> aux;
			memo[i].pb(aux);
			sm += aux;
		}
		sum.pb(sm);
	}

	// fr(i, sum.size()) sum[i] = m[sum[i]];

	vector<pii> ans; 
	map<ll, int> forsum;
	ans.pb({0,0});
	int cnt = 1;

	fr(i, k){

		fr(j, nis[i]){

			int aux = sum[i] - memo[i][j];

			if (forsum[aux] == 0){
				forsum[aux] = cnt++;
				ans.pb({i, j});
				continue;
			}

			int ind = forsum[aux];

			if (ans[ind].f != i){
				p(YES);
				cout << i+1 << " " << j+1 << endl;
				cout << ans[ind].f+1 << " " << ans[ind].s+1 << endl;
				return 0;
			}

		}

	}

	p(NO);

}
