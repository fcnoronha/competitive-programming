//www.spoj.com/problems/XMAX/

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

void gauss (vl a, ll &ans) {

    ll n = a.size();
    ll m = 62;

    for (ll col=m, row=0; col >= 0 && row<n; col--) {

        ll sel = -1;
        for (ll i=row; i<n; ++i)
            if (a[i] & (1LL<<col)) {
                sel = i;
                break;
            }

        if (sel == -1) continue;

        swap(a[sel], a[row]);

        for (ll i=row+1; i<n; ++i)
            if (a[i] & (1LL<<col))
                a[i] ^= a[row];

        ++row;
    }

    fr(i, n)
        ans = max(ans, ans^a[i]);

}


int main(){
    //fastio

    int n;
    cin >> n;

    vl a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    reverse(all(a));

    ll ans = 0ll;
    gauss(a, ans);
    p(ans);
}
