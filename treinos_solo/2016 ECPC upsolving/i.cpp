//codeforces.com/gym/101147/problem/I

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
    freopen("walk.in", "r", stdin);
    fastio;

    int t;
    cin >> t;
    while (t--) {
        
        ll n, m;
        cin >> n >> m;

        vector< pair<double, int> > evt;
        fr(i, n) {
            ll x, y, r, rr;
            cin >> x >> y >> r;
            rr = m-r;
            if (abs(y) > rr) continue;

            double dt = sqrt((rr*rr) - (y*y));
            evt.pb({double(x) - dt, -r});
            evt.pb({double(x) + dt, r});
        }

        sort(all(evt));
        int cnt = 0, ans = 0;
        for (auto e: evt) {
            cnt += -e.s;
            ans = max(ans, cnt);
        }

        p(ans);
    }
}
