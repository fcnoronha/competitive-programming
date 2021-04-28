#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<double,double> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

double euc(pii a, pii b) {
    return sqrt( (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s) );
}

double get_min(pii a, pii c, pii d) {

    double ret = 10000000.0;
    double l = 0.0, r = 1.0;
    fr(abc, 100) {

        double m1 = l + (r-l) / 3;
        double m2 = r - (r-l) / 3;

        pii b1 = { c.f*m1 + d.f*(1.0-m1), c.s*m1 + d.s*(1.0-m1)  };
        double f1 = euc(a, b1);   

        pii b2 = { c.f*m2 + d.f*(1.0-m2), c.s*m2 + d.s*(1.0-m2)  };
        double f2 = euc(a, b2);

        ret = min({ret, f1, f2});
        
        if (f1 > f2) l = m1;
        else		 r = m2;
    }

    return ret;

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;

    while (t--) {

        int n; cin >> n;
        vector<pii> inn(n);
        fr(i, n) cin >> inn[i].f >> inn[i].s;

        int m; cin >> m;
        vector<pii> out(m);
        fr(i, m) cin >> out[i].f >> out[i].s;

        double ans = 10000000.0;
        fr (i, n) fr(j, m) {
            ans = min(ans, get_min(inn[i], out[j], out[(j+1)%m]));
            ans = min(ans, get_min(out[j], inn[i], inn[(i+1)%n]));
        }

        cout << setprecision(6) << fixed << ans/2.0 << endl;
    }
}
