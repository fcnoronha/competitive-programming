//codeforces.com/contest/1342/problem/C

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

        ll a, b, q;
        cin >> a >> b >> q;

        ll m = a*b, amt = 0ll;
        vl pref(m+2, 0);
        frr(x, m) {
            pref[x] = pref[x-1];
            if ( (x%a)%b != (x%b)%a )
                amt++, pref[x]++;
        }
        while (q--) {
            ll l, r;
            cin >> l >> r;
 
            l--;
            ll al = 0ll, ar = 0ll;
            al = amt*(l/m) + pref[l%m];
            ar = amt*(r/m) + pref[r%m];
 
            cout << ar-al << " ";
        }
        cout << endl;
    }
}