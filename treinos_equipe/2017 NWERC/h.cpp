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

        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll ans = a*a + b*b + c*c + min({a,b,c})*7ll;
        for (ll i = 0; i <= min(d, 100ll); i++) {
            for (ll j = 0; j+i <= min(d, 100ll); j++) {
                ll k = d - (i+j);
                ll aa = a+i, bb = b+j, cc = c+k;
                ans = max(ans, aa*aa + bb*bb + cc*cc + min({aa,bb,cc})*7ll);
            }
        }

        ll aa = a+d, bb = b, cc = c;
        ans = max(ans, aa*aa + bb*bb + cc*cc + min({aa,bb,cc})*7ll);

        aa = a, bb = b+d, cc = c;
        ans = max(ans, aa*aa + bb*bb + cc*cc + min({aa,bb,cc})*7ll);

        aa = a, bb = b, cc = c+d;
        ans = max(ans, aa*aa + bb*bb + cc*cc + min({aa,bb,cc})*7ll);

        p(ans);
    } 
}