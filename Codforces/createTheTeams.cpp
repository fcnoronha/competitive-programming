//codeforces.com/contest/1380/problem/C

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
    fastio;

    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        ll a[n];
        fr(i,n) cin >> a[i];

        sort(a, a+n); reverse(a,a+n);

        ll ans = 0, amt[n];
        ms(amt, 0ll);

        fr(i, n) {
            ll aux = (x+a[i]-1)/a[i];

            if (aux > i+1) continue;
            amt[i] = 1;
            if (i-aux >= 0) amt[i] += amt[i-aux];

            ans = max(ans, amt[i]);
        }

        p(ans);
    }
}
