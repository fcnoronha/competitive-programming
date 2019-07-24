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

const int INF = 0x3f3f3f3f;

int main(){
	fastio

	int n; cin >> n;

	vi v;

	for(int i=0;i<n;i++){
		int a,b; cin >> a >> b;
		v.pb(a);
		v.pb(b);
	}
	sort(all(v));

	int ini=0;
	int end = 2*n-1;

	ll mx = 0;
	ll mn = 0x3f3f3f3f3f3f3f;

	while(ini<end){
		ll now = v[ini]+v[end];
		mx=max(now,mx);
		mn=min(now,mn);
		ini++;end--;
	}

	cout << abs(mn-mx) << endl;

}
