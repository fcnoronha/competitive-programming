#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ld dist(pdd x, pdd y) {
    return sqrt((x.f-y.f)*(x.f-y.f) + (x.s-y.s)*(x.s-y.s));
}

ld d1, d2, mx, ans;

void ts_3(pdd a, pdd b, pdd c) {

    ld l = 0.0, r = 1.0;
    fr(k, 300) {
        
        ld t1 = l+(r-l)/3.0;
        ld t2 = r-(r-l)/3.0;

        pdd p1 = {(a.f*t1 + b.f*(1.0-t1)), (a.s*t1 + b.s*(1.0-t1))};
        pdd p2 = {(a.f*t2 + b.f*(1.0-t2)), (a.s*t2 + b.s*(1.0-t2))};

        ld f1 = dist(p1, c);   
        ld f2 = dist(p2, c);    

        ans = min({ans, f1, f2});
        if (f1 > f2) l = t1;
        else		 r = t2;
    }
}

void ts_2(pdd a, pdd b, pdd c, pdd d) {
    
    ld l = 0.0, r = 1.0;
    fr(k, 300) {
    
        ld t1 = l+(r-l)/3.0;
        ld t2 = r-(r-l)/3.0;

        pdd p1, p2;
        p1 = {(a.f*t1 + b.f*(1.0-t1)), (a.s*t1 + b.s*(1.0-t1))};
        p2 = {(c.f*t1 + d.f*(1.0-t1)), (c.s*t1 + d.s*(1.0-t1))};
        ld f1 = dist(p1, p2);   

        p1 = {(a.f*t2 + b.f*(1.0-t2)), (a.s*t2 + b.s*(1.0-t2))};
        p2 = {(c.f*t2 + d.f*(1.0-t2)), (c.s*t2 + d.s*(1.0-t2))};
        ld f2 = dist(p1, p2);    

        ans = min({ans, f1, f2});
        if (f1 > f2) l = t1;
        else		 r = t2;
    }
}

pdd ts_1(pdd a, pdd b) {

    ld l = 0.0, r = 1.0;
    fr(k, 300) {
    
        ld m1 = l + (r-l) / 3.0;
        ld m2 = r - (r-l) / 3.0;

        pdd p1 = {a.f*m1 + b.f*(1.0-m1), a.s*m1 + b.s*(1.0-m1)};
        pdd p2 = {a.f*m2 + b.f*(1.0-m2), a.s*m2 + b.s*(1.0-m2)};

        ld f1 = abs(d2 - dist(p1, a));   
        ld f2 = abs(d2 - dist(p2, a));     

        if (f1 > f2) l = m1;
        else		 r = m2;
    }
    
    return {a.f*l + b.f*(1.0-l), a.s*l + b.s*(1.0-l)};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    pdd a, b, c, d;
    cin >> a.f >> a.s >> b.f >> b.s;
    cin >> c.f >> c.s >> d.f >> d.s;

    d1 = dist(a, b);
    d2 = dist(c, d);
    mx = max(d1, d2);
    ans = 10e18;

    if (d1 < d2) {
        swap(d1, d2);
        swap(a, c);
        swap(b, d);
    }

    pdd fim_ab = ts_1(a, b);
    ts_2(a, fim_ab, c, d);
    ts_3(fim_ab, b, d);

    cout << setprecision(7) << fixed << ans << endl;
}
