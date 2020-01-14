//codeforces.com/contest/1285/problem/B

#include "bits/stdc++.h"
using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define p(x) cout << x << "\n"

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        ll a[n], sm = 0ll;
        fr(i, n) cin >> a[i], sm += a[i];

        ll m1 = -LINF, m2 = -LINF, aux;

        aux = 0ll;
        frr(i, n-1) {
            aux = max(0ll, aux+a[i]);
            m1 = max(m1, aux);
        }
        aux = 0ll;
        fr(i, n-1) {
            aux = max(0ll, aux+a[i]);
            m2 = max(m2, aux);
        }

        if (m1 < sm && m2 < sm) p("YES");
        else p("NO");
    }
}
