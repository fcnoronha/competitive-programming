//codeforces.com/contest/580/problem/D

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ll n, m, k;
ll a[20];
ll rule[20][20]; // [x][y]
ll memo[20][(1<<20)];

ll pd(int prev, int mask) {

    if (__builtin_popcount(mask) == m)
        return 0ll;

    if (memo[prev][mask] != -1ll) return memo[prev][mask];

    ll pd_aux = 0ll;
    fr(i, n) {

        if (mask & (1<<i)) continue;

        pd_aux = max(pd_aux, a[i] + rule[prev][i] + pd(i, mask|(1<<i)));
    }

    return memo[prev][mask] = pd_aux;
}

int main(){
    fastio

    cin >> n >> m >> k;

    fr(i, n) cin >> a[i];

    ll x, y, c;
    fr(i, k) {
        cin >> x >> y >> c;

        rule[x-1][y-1] = c;
    }

    ms(memo, -1ll);
    ll ans = pd(19, 0);

    p(ans);
}
