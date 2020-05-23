//codeforces.com/contest/1345/problem/B

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

    vl amt;
    for (ll i = 1;; i++) {
        ll aux = ((3*(i*i) + i)/2ll);
        if (aux > 1000000000ll) break;
        amt.pb(aux);
    }

    int t;
    cin >> t;
    while (t--) {

        ll n;
        cin >> n;
        int ans = 0;

        while (n > 1) {
            ll oi = *(upper_bound(all(amt), n)-1);
            //dbg(n); dbg(oi);
            n -= oi;
            ans++;
        }

        p(ans);
    }
}
