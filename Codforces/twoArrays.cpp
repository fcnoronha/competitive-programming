//codeforces.com/contest/1288/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

const ll mod = 1000000007;

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

ll invmod(ll x){
	return fastexp(x, mod-2);
}

ll fat(int x) {
    if (x <= 1) return 1ll;
    return (x*fat(x-1))%mod;
}

int main(){
    fastio;

    ll n, m;
    cin >> n >> m; 

    int ans = (fat(n+2*m-1) * invmod( (fat(2*m)*fat(n-1))%mod ))%mod;
    p(ans);
}
