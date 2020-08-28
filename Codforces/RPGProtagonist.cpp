//codeforces.com/contest/1400/problem/B


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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {

        ll p, f;
        cin >> p >> f;

        ll cs, cw;
        cin >> cs >> cw;

        ll s, w;
        cin >> s >> w;

        if (s > w) {
            swap(s, w);
            swap(cs, cw);
        }
        // now s < w

        ll oi1 = p/s, oi2 = f/s;
        if (oi1+oi2 <= cs) {
            p(oi1+oi2);
            continue;
        }

        ll ans = 0ll;
        for (ll k = 0; k <= cs; k++) {
            ll sobp = p - (s*k), sobf = f - ((cs-k)*s);
            if (sobp < 0 || sobf < 0) continue; 
            ll can1 = min(cw, sobp/w), can2 = min(cw-can1, sobf/w);
            ans = max(ans, can1+can2+cs);
        }    

        p(ans);
    }
}
