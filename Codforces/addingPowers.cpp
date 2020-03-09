//codeforces.com/contest/1312/problem/C

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

        ll n, k;
        cin >> n >> k;
        ll a[n];
        fr(i, n) cin >> a[i];

        vl pused(140, 0ll);
        ll max_p = 0ll;
        fr(i, n) {
            if (a[i] == 0ll) continue;
            if (a[i] == 1ll) {
                pused[0]++;
                a[i] = 0ll;
                continue;
            }
            while (a[i]) {
                ll p = 0ll;
                while (pow(k, p) <= a[i]) p++;
                p--;
                max_p = max(max_p, p);
                a[i] -= pow(k, p);
                pused[p]++;
            }
        }

        fr(i, n) {
            if (a[i]) {
                p("NO");
                goto fim;
            }
        }

        fr(i, max_p + 1) {
            if (pused[i] > 1) {
                p("NO");
                goto fim;
            }
        }  

        p("YES");
        fim:;
    }
}
