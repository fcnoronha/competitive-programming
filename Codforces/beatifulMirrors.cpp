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

const ll mod = 998244353;

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

int main(){

    int n;
    cin >> n;

    ll p[n];
    fr(i, n) cin >> p[i], p[i] = p[i]*fastexp(100, mod-2)%mod;

    ll a = 1ll, b = 0ll;
    fr(i, n) {
        a = a*fastexp(p[i], mod-2)%mod;
        b = b*fastexp(p[i], mod-2)%mod;
        a = (a+(p[i]-1ll)*fastexp(p[i], mod-2))%mod;
        b = (b-fastexp(p[i], mod-2)+mod)%mod;
    }

    ll ans = (mod-b)*fastexp(a, mod-2)%mod;
    cout << ans << endl;
}
