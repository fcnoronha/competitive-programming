//vjudge.net/contest/376169#problem/E

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

int n, k;
bool solve(double x, vector<double> &aux) {

    vector<double> v;
    v.pb(0.0);

    fr(i, n) v.pb(aux[i] + v[i] - x);
    
    int idx = 0;
    double mn = v[idx];

    for (int i = k; i <= n; i++) {
        if (v[i] >= mn) return 1;
        mn = min(mn, v[++idx]);
    }

    return 0;
}

int main() {
    fastio;

    cin >> n >> k;

    vector<double> v(n);
    fr(i, n) cin >> v[i];

    double lo = 0.0, hi = 10000000.0, ans = 0.0;
    fr(i, 100) {
        double m = (lo+hi)/2.0;
        if (solve(m, v)) lo = ans = m;
        else             hi = m;
    }

    cout << setprecision(6) << fixed << ans << endl;
}
