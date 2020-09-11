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

    int n;
    cin >> n;

    map<string, double> mp;
    map<string, bool> foi;
    foi["pink"] = 1;
    while (n--) {
        string s, t;
        cin >> s >> t;
        double r;
        cin >> r;

        if (!foi[t]) continue;
        if (!foi[s]) mp[s] = -1e10;
        mp[s] = max(mp[s], mp[t]+log2(r));
        foi[s] = 1;
    }

    double ans = pow(2.0, mp["blue"]);
    if (!foi["blue"]) ans = 0.0;

    cout << setprecision(8) << fixed << min(ans, 10.0) << endl;
}
