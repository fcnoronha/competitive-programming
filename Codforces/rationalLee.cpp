//codeforces.com/contest/1369/problem/C

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

        ll a[n], w[k];
        fr(i, n) cin >> a[i];
        fr(i, k) cin >> w[i];

        sort(a, a+n); 
        sort(w, w+k); reverse(w, w+k);
        ll ans = 0ll, idx = 0;

        fr(i, k) {
            if (w[i] < 2) break;
            ans += a[idx];
            idx += w[i]-1;
        }

        fr(i, k) {
            ans += a[idx];
            if (w[i] == 1) ans += a[idx];
            idx++;
        }

        p(ans);
    }
}
