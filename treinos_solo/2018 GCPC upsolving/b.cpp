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

#define M_PI 3.14159265358979323846

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
    fastio;

    cout << fixed << setprecision(9);

    ld p1, p2, q1, q2;
    ld cx, cy, r;

    cin >> p1 >> p2;
    cin >> q1 >> q2;
    cin >> cx >> cy >> r; // dumb;
    cin >> cx >> cy >> r;

    ld d1 = dist(p1, p2, cx, cy);
    ld d2 = dist(q1, q2, cx, cy);
    ld x1 = sqrt(d1 - r*r);
    ld x2 = sqrt(d2 - r*r);

    ld a1 = atan2(x1, r) + atan2(x2, r);

    ld ans = x1 + x2;

    ld bigd = dist(p1, p2, q1, q2);
    ld delta = (bigd - d2 + d1)/(sqrt(4.0*bigd));
    ld h = sqrt(d1 - delta*delta);

    //dbg(d1); dbg(d2);
    //dbg(delta); dbg(bigd); dbg(h);

    ld a2 = atan2(delta, h) + atan2(sqrt(bigd)-delta, h);

    //dbg(ans);

    ld alpha = a2 - a1;
    ld per = alpha * r;

    //dbg(alpha); dbg(2*M_PI - alpha);
    //dbg(a1); dbg(a2); dbg(alpha);
    //dbg(per);

    ans += per;
    cout << ans << endl;
}
