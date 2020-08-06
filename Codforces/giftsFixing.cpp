//codeforces.com/contest/1399/problem/B

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
        ll n;
        cin >> n;

        ll a[n], b[n];
        fr(i, n) cin >> a[i];
        fr(i, n) cin >> b[i];

        ll ma = a[0], mb = b[0];
        fr(i, n) ma = min(a[i], ma);
        fr(i, n) mb = min(b[i], mb);

        ll ans = 0ll;
        fr(i, n) {

            ll db = b[i] - mb;
            ll da = a[i] - ma;
            ll aux = min(db, da);
            ans += aux;
            ans += da-aux + db-aux;
        }

        p(ans);
    }
}
