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

#define point pll
typedef pair<pll, pll> line;

pll distPointLine(point p, point a, point b) {
   
    // ax + by + c = 0
    ll ac = (a.s - b.s);
    ll bc = (b.f - a.f);
    ll cc = (a.f * b.s) - (b.f*a.s);

    ll d1 = ( ac*p.f + bc*p.s + cc)*( ac*p.f + bc*p.s + cc);
    ll d2 = ac*ac + bc*bc;
    
    return {d1, d2};
}

int main(){
    fastio;

    int n;
    cin >> n;

    map<pll, vector<line>> cof;

    fr(i, n) {

        point p1, p2;
        cin >> p1.f >> p1.s;
        cin >> p2.f >> p2.s;

        ll a = p1.s-p2.s;
        ll b = p1.f-p2.f;

        ll g = __gcd(abs(a), abs(b));
        a /= g, b /= g;

        if (a<0 && b<0) {
            a = -a;
            b = -b;
        }

        cof[{a,b}].pb({p1,p2});
    }

    map<pair<pll,pll>, ll> cnt;
    for (auto x: cof) {

        ll a = x.f.f;
        ll b = x.f.s;
        auto v = x.s;

        fr(i, v.size()) {
            for (int j = i+1; j < v.size(); j++) {

                auto d = distPointLine(v[i].f, v[j].f, v[j].s);
                cnt[{{a,b},d}]++;
            }
        }
    }


    ll ans = 0;
    for (auto x: cof) {

        ll a = x.f.f;
        ll b = x.f.s;
        auto v = x.s;

        fr(i, v.size()) {
            for (int j = i+1; j < v.size(); j++) {
                auto d = distPointLine(v[i].f, v[j].f, v[j].s);
                ans += cnt[{{b,-a},d}];
                ans += cnt[{{-b,a},d}];
            }
        }
    }

    p(ans);
}
