// codeforces.com/contest/1091/problem/C

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
		
	ll n;
	cin >> n;

	vl ans;

	for (int k = 1; k*k <= n; k++){

		if (!(n%k)){

			ans.pb(n*(k-1)/2 + k);

			if (k*k < n)
				ans.pb((n*(n/k - 1)/2) + n/k);
		}
	}

	sort(ans.begin(), ans.end());

	pv(ans);
}
