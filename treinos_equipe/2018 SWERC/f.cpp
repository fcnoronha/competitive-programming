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

#define x first.first
#define y first.second
#define g second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

typedef pair<pll, ll> point;

ll is_left(point a, point b, point c) {
    ll det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // c is to the left
    if (det < 0) return -1; // c is to the right
    return 0;               // c is collinear
}

point center;
bool cmp(point a, point b) {
    if (a.x - center.x >= 0 && b.x - center.x < 0)
        return true;
    if (a.x - center.x < 0 && b.x - center.x >= 0)
        return false;
    return (is_left(center, a, b) == 1);
}

ll solve(int idx, vector<point> &pt) {
    
    ll cnta = 0ll, cntb = 0ll;
    fr(i, pt.size()) {
        if (i == idx) continue;
        if (is_left(center, pt[idx], pt[i]) == 1) cnta += pt[i].g;
        if (is_left(center, pt[idx], pt[i]) == -1) cntb += pt[i].g;
    }
    return abs(cnta-cntb);
}

ll ts(vector<point> &aux) {
    ll l = 0, r = aux.size(), ans = LLONG_MAX;
    fr(k, 30) {
        ll lm = l + (r-l)/3;
        ll rm = r - (r-l)/3;
        
        ll sl = solve(lm, aux);
        ll sr = solve(rm, aux);
        if (sl > sr) {
            ans = min(ans, sr);
            l = lm;
        }
        else {
            ans = min(ans, sl);
            r = rm;
        }
    }
    ans = min(ans, solve(0, aux));
    ans = min(ans, solve(aux.size()-1, aux));
    return ans;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    point pt[n];
    fr(i, n) cin >> pt[i].x >> pt[i].y >> pt[i].g;

    ll ans = LLONG_MAX;
    fr(i, n) {
        center = pt[i];
        vector<point> aux;
        fr(j, n) {
            if (j == i) continue;
            aux.pb(pt[j]);
        }
        sort(all(aux), cmp);
        ans = min(ans,ts(aux));
    }

    p(ans);
}
