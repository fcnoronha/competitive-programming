//codeforces.com/contest/1355/problem/A

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

ll mul(ll x) {

    ll mn = x%10, mx = x%10;
    while (x) {
        ll d = x%10;
        x /= 10;
        mn = min(mn, d);
        mx = max(mx, d);
    }
    return mn*mx;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        ll a, k;
        cin >> a >> k;
        k--;
        while (k && mul(a)) {
            k--;
            a = a + mul(a);
        }
        p(a);
    }
}
