//codeforces.com/contest/1334/problem/C

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

        ll n;
        cin >> n;
        pll m[n];
        ll ori[n];
        fr(i, n) {
            cin >> m[i].f >> m[i].s;
            ori[i] = m[i].f;
        }

        fr(i, n) m[(i+1)%n].f -= m[i].s;

        ll ans = 0ll, mn = LINF, mni = -1;
        fr(i, n) {
            if (m[i].f > 0) {
                ans += m[i].f;
                ori[i] -= m[i].f;
            }
            mn = min(mn, ori[i]);
        }
        ans += mn;

        p(ans);
    }
}
