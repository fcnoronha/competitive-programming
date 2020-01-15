#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(iii, x.size()) cout << x[iii] << " \n"[iii==x.size()-1]
#define pvv(x, n) for(int iii = 1, vaca = nnn; i <= nnn;i++) cout << x[i] << " \n"[iii==nnn];

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

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

const ld pi = 3.14159265359;

int main(){
    fastio;

    ll p1, p2, q1, q2;
    int cx, cy, r;

    cin >> p1 >> p2;
    cin >> q1 >> q2;
    cin >> cx >> cy >> r; // dumb;
    cin >> cx >> cy >> r;

    ll d1 = dist(p1, p2, cx, cy);
    ll d2 = dist(q1, q2, cx, cy);
    ll x1 = (d1 - r*r);
    ll x2 = (d2 - r*r);

    ld ans = sqrt(x1) + sqrt(x2);

    ld tg1 = sqrt(x1)/ld(r);
    ld tg2 = sqrt(x2)/ld(r);

    ll bigd = dist(p1, p2, q1, q2);
    ld delta = ld(bigd - d2 + d1)/(2.0*sqrt(bigd));
    ld h = sqrt(delta*delta - ld(d1));

    ld tg3 = (delta)/h;
    ld tg4 = ((bigd-delta))/h*1.0;

    ld a1 = atan(tg1) + atan(tg2);
    ld a2 = atan(tg3) + atan(tg4);

    ld alpha = a2 - a1;
    ld per = alpha*r;


    ans += per;
    cout << fixed << setprecision(9) << ans << endl;
}
