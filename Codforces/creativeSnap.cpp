//codeforces.com/contest/1111/problem/C

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

vi pos;
ll n, k, a, b;

ll solve(ll l, ll r){

	ll aux1 = (upper_bound(all(pos), r) - lower_bound(all(pos), l));
	if (aux1 == 0) return a;

	aux1 *= (r-l+1)*b;

	ll mid = (l+r)/2;

	if (l == r) return aux1;
	return min(aux1, solve(l, mid)+solve(mid+1, r));
}	

int main(){
	fastio
	
	cin >> n >> k >> a >> b;
	pos.resize(k);
	fr(i, k) cin >> pos[i];

	sort(all(pos));

	cout << solve(1, 1<<n) << endl;
}
