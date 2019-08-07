//www.codechef.com/problems/MIXFLVOR

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

struct gauss {
    vl nuns;

    void add(ll x) {
        // same as x & (1<<i), bit wo taking care of binary indexes
        fr(i, nuns.size())
            if ((nuns[i]^x) < x)
                x ^= nuns[i];
        // as x^0 == x we ignore the 0-case
        if (x) {
            nuns.pb(x);
            sort(all(nuns));
            reverse(all(nuns));
        }
    }

    ll get_ans() {
        ll ans = 0;
        for (auto x : nuns)
            ans = max(ans, ans^x);
        return ans;
    }

    gauss operator+(gauss other) {
        gauss ret;
        for (auto o : other.nuns)
            ret.add(o);
        for (auto o : nuns)
            ret.add(o);
        return ret;
    }
};

int main(){
    fastio

    int t;
    cin >> t;

    while (t--) {

        ll n, k;
        cin >> n >> k;

        vl c(n), f(n);
        fr(i, n)
            cin >> c[i] >> f[i];

        gauss fwd;
        stack<gauss> bkd;
        int r = 0;
        ll sm = 0ll, ans = 0ll;

        // r-right l-left
        fr(l, n) {

            // new segment
            if (r < l) {
                fwd = gauss();
                sm = 0ll;
                r = l;
            }

            // Maximum size of current segment
            while (r < n && sm+c[r] <= k) {
                fwd.add(f[r]);
                sm += c[r];
                r++;
            }

            ans = max(ans, fwd.get_ans());
            if (!bkd.empty())
                ans = max(ans, (fwd+bkd.top()).get_ans());

            if (bkd.empty()) {
                gauss aux;
                for (int j = r-1; j >= l; j--) {
                    aux.add(f[j]);
                    bkd.push(aux);
                }
                fwd = gauss();
            }

            if (r != l)
                bkd.pop();
            sm -= c[l];
        }

        p(ans);
    }
}
