#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

pll pt[4], sides[4];
ll ans;

ll dist(pll a, pll b) {
    return abs(a.f-b.f)+abs(a.s-b.s);
}

ll f(ll sd, ll sqr, pll ori) {

    pll a = ori;
    pll b = {a.f + sides[sqr].f*sd, a.s + sides[sqr].s*sd};
    pll c = {a.f, b.s};
    pll d = {b.f, a.s};

    ll ret = LINF;
    vi pp({0,1,2,3});
    do {

        ll oi = 0;
        oi += dist(a, pt[pp[0]]);
        oi += dist(b, pt[pp[1]]);
        oi += dist(c, pt[pp[2]]);
        oi += dist(d, pt[pp[3]]);

        ret = min(ret, oi);
    } while (next_permutation(all(pp)));    


    ans = min(ans, ret);
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    sides[0] = {-1,-1};
    sides[1] = {1,-1};
    sides[2] = {-1,1};
    sides[3] = {1,1};

    int t; cin >> t;
    while (t--) {

        fr(i, 4) cin >> pt[i].f >> pt[i].s;
        ans = LINF;

        fr(i, 4) fr(j, 4) fr(k, 4) fr(sqr, 4) {

            if (k == i) continue;
            f(abs(pt[i].f-pt[k].f), sqr, {pt[i].f, pt[j].s});
        }


        fr(i, 4) fr(j, 4) fr(k, 4) fr(sqr, 4) {

            if (k == j) continue;
            f(abs(pt[j].s-pt[k].s), sqr, {pt[i].f, pt[j].s});
        }

        p(ans);
    }
}