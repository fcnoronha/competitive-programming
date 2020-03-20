//codeforces.com/contest/1323/problem/B

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

#define maxn 40009
ll cnta[maxn], cntb[maxn];
ll a[maxn], b[maxn];
ll ans;

int main() {
    fastio;

    ll n, m, k, aux;
    cin >> n >> m >> k;
    fr(i, n) cin >> a[i];
    fr(i, m) cin >> b[i];

    aux = 0ll;
    fr(i, n) {
        if (a[i] == 0) {
            aux = 0ll;
            continue;
        }
        aux++;
        cnta[aux]++;
    }

    aux = 0ll;
    fr(i, m) {
        if (b[i] == 0) {
            aux = 0ll;
            continue;
        }
        aux++;
        cntb[aux]++;
    }

    for (int i = n; i > 0; i--) cnta[i] += cnta[i+1];
    for (int i = m; i > 0; i--) cntb[i] += cntb[i+1];

    frr(d, min(k, n)) {
        if (k%d) continue;
        if (d > n || (k/d) > m) continue;
        ans += cnta[d]*cntb[k/d];
    }

    p(ans);
}
