//codeforces.com/contest/1303/problem/D

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

    int t;
    cin >> t;
    while (t--) {

        ll n, m, sm = 0ll;
        cin >> n >> m;
        vi amt(100, 0);
        fr(k, m) {
            ll x;
            cin >> x;
            int i = 0;
            while ((x & (1<<i)) == 0) i++;
            amt[i]++;
            sm += x;
        }

        if (n > sm) {
            p(-1);
            continue;
        }

        int ans = 0, i = 0;
        while (i < 60) {
            if (!(n & (1ll<<i))) {
                amt[i+1] += amt[i]/2;
                i++;
                continue;
            }
            if (amt[i]) {
                amt[i]--;
                amt[i+1] += amt[i]/2;
                i++;
                continue;
            }
            while (i < 60 && !amt[i]) {
                i++;
                ans++;
            }
            amt[i]--;
        }

        p(ans);
    }
}
