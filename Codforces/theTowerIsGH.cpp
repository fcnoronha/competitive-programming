//codeforces.com/contest/1075/problem/C

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

int main(){
	fastio
	
	int n, m;
	cin >> n >> m;

	vi ver(n);
	fr(i, n) cin >> ver[i];
	ver.pb(1000000000);
	sort(all(ver));

	vi hor;
	fr(i, m){
		int x1, x2, y;
		cin >> x1 >> x2 >> y;

		if (x1 > 1) continue;

		hor.pb(x2);
	}
	m = hor.size();

	sort(all(hor));

	int ans = INT_MAX, p = 0;
	fr(i, n+1){

		while (p < m && hor[p] < ver[i]) p++;

		ans = min(ans, i+m-p);
	}

	cout << ans << endl;
}
