//onlinejudge.org/external/14/1406.pdf

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

int main() {
    fastio;

    int cas = 1, n;
    while (cin >> n && n != -1) {

        vl v(n);
        fr(i, n) cin >> v[i];

        ll a[16][n];
        fr(t, 16) {
            fr(i, n) 
                a[t][i] = v[i]%(1<<(t+1));
            sort(a[t], a[t]+n);
        }

        ll d = 0ll, ans = 0ll, t;
        char op;
        while (cin >> op && op != 'E') {
            cin >> t;
            if (op == 'C') {
                d = (d+t)%(1<<16);
                continue;
            }
            ll mod = (1<<(t+1));
            ll aux = d%mod;
            ll l = ((1<<t) - aux + mod)%mod;
            ll r = ((1<<(t+1)) - 1 - aux + mod)%mod;
            if (l <= r) {
                auto il = lower_bound(a[t], a[t]+n, l);
                auto ir = upper_bound(a[t], a[t]+n, r);
                ans += distance(il, ir);
            }
            else {
                auto il = lower_bound(a[t], a[t]+n, l);
                auto ir = upper_bound(a[t], a[t]+n, r);
                ans += n-distance(ir, il);
            }
        }
    
        cout << "Case " << cas++ << ": " << ans << endl;
    }
}
