//codeforces.com/contest/1285/problem/D

#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio;

    ll n;
    cin >> n;

    ll ans1, ans2;

    if (n == 1ll) {
        cout << "1 1\n";
        return 0;
    }

    ll ans = LINF;
    for (ll d = 1ll; d*d <= n; d++) {
        if (n%d == 0) {
            
            ll g = __gcd(d, n/d);
            if (d*(n/d)/g == n) ans = min(ans, max(d, n/d));
        }
    }    

    cout << ans << " " << n/ans << endl;
}
