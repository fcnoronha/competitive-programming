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

map<ll, pll> loc;

ll solve(ll h) {

    ll ret = 0;
    for (auto x: loc) {
        auto p = x.s;

        if (h <= p.f) {
            ret += (p.s - h);
            continue;
        }
        if (h >= p.s) {
            ret += (h - p.f);
            continue;
        }

        ret += abs(p.s - h);
        ret += abs(h - p.f);
    }   

    return ret*2;
}

int main() {
    fastio;

    ll x, y;
    cin >> x >> y;
    ll n;
    cin >> n;

    fr(i, n) {
        ll xi, yi;
        cin >> xi >> yi;

        if (loc.find(xi) == loc.end()) 
            loc[xi] = {yi, yi};

        loc[xi].f = min(loc[xi].f, yi);
        loc[xi].s = max(loc[xi].s, yi);
    }

    ll l = 0, r = y, ans = LLONG_MAX;
    fr(k, 100) {
        ll lm = l + (r-l) / 3;
        ll rm = r - (r-l) / 3;
        
        if (solve(lm) > solve(rm)) {
            ans = min(ans, solve(rm));
            l = lm;
        }
        else {
            ans = min(ans, solve(lm));
            r = rm;
        }
    }

    p(ans+x-1);
}
