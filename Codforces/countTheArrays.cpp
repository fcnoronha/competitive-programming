//codeforces.com/contest/1312/problem/D

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

#define maxn 200009
const ll mod = 998244353;

ll fat[maxn];

ll fastexp(ll b, ll e) {
    if (!e) return 1ll;
    ll ans = fastexp(b, e/2);
    ans = (ans*ans)%mod;
    if (e%2) ans = (ans*b)%mod;
    return ans;
}

ll invmod(ll x) {
    return fastexp(x, mod-2);
}

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    if (n <= 2) {
        p(0);
        return 0;
    }

    fat[0] = 1ll;
    frr(i, max(n, m)) fat[i] = (fat[i-1]*i)%mod;

    ll ans = 0ll;
    ans = fat[m] * (invmod(fat[n-1])*invmod(fat[m-n+1])%mod)%mod;
    ans = (ans * (n-2ll))%mod;
    ans = (ans * fastexp(2ll, n-3ll))%mod;

    p(ans);
}
