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
    cout << setprecision(6) << fixed;

    int t;
    cin >> t;
    while (t--) {

        ll c, n;
        cin >> c >> n;

        unordered_map<string, double> mp;
        mp["JD"] = 1.0;
        fr(i, c) {
            string cr;
            double d;
            cin >> cr >> d;
            mp[cr] = d;
        }

        double ans = 0.0;
        fr(i, n) {
            string cr;
            double d;
            cin >> d >> cr;
            ans += d*mp[cr];
        }

        cout << ans << '\n';
    }
}
