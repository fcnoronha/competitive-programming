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

    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    ll p[a], q[b], r[c];
    fr(i, a) cin >> p[i];
    fr(i, b) cin >> q[i];
    fr(i, c) cin >> r[i];

    sort(p, p+a); reverse(p, p+a);
    sort(q, q+b); reverse(q, q+b);
    sort(r, r+c); reverse(r, r+c);

    frr(i, c-1) r[i] += r[i-1];
    ll red = 0, green = 0, ans = 0;

    if (x+y-1 < c) ans = r[x+y-1];

    ll ac = 0ll, tk = 0;
    while (red < x && green < y) {

        if (p[red] > q[green]) ac += p[red++];
        else                   ac += q[green++];
        tk++;

        ll amt = x+y-tk;
        if (amt > 0 && amt <= c) ans = max(ans, ac+r[amt-1]);
    }

    while (red < x) {
        ac += p[red++];
        tk++;
        ll amt = x+y-tk;
        if (amt > 0 && amt <= c) ans = max(ans, ac+r[amt-1]);
    }

    while (green < y) {
        ac += q[green++];
        tk++;
        ll amt = x+y-tk;
        if (amt > 0 && amt <= c) ans = max(ans, ac+r[amt-1]);
    }

    ans = max(ans, ac);
    p(ans);
}
