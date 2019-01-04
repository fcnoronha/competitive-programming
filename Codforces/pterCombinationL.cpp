// codeforces.com/contest/1097/problem/B

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

	int n;
	cin >> n;

	vi a(n);
	fr(i, n){
		cin >> a[i];
	}

	vi ans;
	fr(i, n){

		if (ans.size() == 0){
			ans.pb(a[0]);
			continue;	
		}

		int mem = ans.size();
		fr(j, mem) ans.pb(ans[j] + a[i]);
		fr(j, mem) ans[j] -= a[i];
	}
	
	bool opa = false;
	fr(i, ans.size()) if (ans[i]%360 == 0) opa = true;

	if (opa) p(YES);
	else p(NO);
}
