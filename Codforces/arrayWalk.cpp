//codeforces.com/contest/1389/problem/B

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        ll n, k, z;
        cin >> n >> k >> z;

        ll a[n], ac[n];
        fr(i, n) cin >> a[i];

        ac[0] = a[0];
        frr(i, n-1) ac[i] = ac[i-1] + a[i];

        ll ans = ac[k];
        frr(i, n-1) {
            ll kk = k, aux = 0ll;
            frr(j, z) {
                aux += a[i-1];
                kk--;
                if (kk >= i) ans = max(ans, ac[i]+aux);
                aux += a[i];
                kk--;
                if (kk >= i) ans = max(ans, ac[kk]+aux);
            }
        }

        p(ans);
    }
}
