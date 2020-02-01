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

struct point {
    ll x, y;
    point() { x = y = 0.0; }
    point(ll _x, ll _y) : x(_x), y(_y) {}
    
    double angle() { return atan2(y, x); }

    bool operator < (point other) const {
        if (x != other.x) return x < other.x;
        else return y < other.y;
    }
    bool operator == (point other) const {
        return ((x) == other.x && y == other.y);
    }
    point operator +(point other) const {
        return point(x + other.x, y + other.y);
    }
    point operator -(point other) const {
        return point(x - other.x, y - other.y);
    }
    point operator *(ll k) const {
        return point(x*k, y*k);
    }
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double inner(point p1, point p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

double cross(point p1, point p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

bool ccw(point p, point q, point r) {
    return cross(q-p, r-p) > 0;
}

bool collinear(point p, point q, point r) {
    return cross(p-q, r-p) == 0;
}

typedef vector<point> polygon;

int leftmostIndex(vector<point> &P) {
    int ans = 0;
    for(int i=1; i<(int)P.size(); i++) {
        if (P[i] < P[ans]) ans = i;
    }
    return ans;
}

point pivot(0, 0);

vector<point> large;
vector<point> small;

bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b))
        return inner(pivot-a, pivot-a) < inner(pivot-b, pivot-b);
    return cross(a-pivot, b-pivot) >= 0;
}

polygon convexHull(vector<point> P) {
    int i, j, n = (int)P.size();
    if (n <= 2) return P;
    int P0 = leftmostIndex(P);
    swap(P[0], P[P0]);
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    for(i = 2; i < n;) {
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    reverse(S.begin(), S.end());
    S.pop_back();
    reverse(S.begin(), S.end());
    return S;
}

bool between(point p, point q, point r) {
    return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}

double angle(point a, point o, point b) {
    return acos(inner(a-o, b-o) / (dist(o,a)*dist(o,b)));
}

ll areaTriangle(point &a, point &b, point &c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

bool inPolygon(polygon cv, point p) {

    int n = cv.size();

    ll start = 1, last = n - 1;
    while (last - start > 1) {
        ll mid = (start + last) >> 1;
        if (areaTriangle(cv[0], cv[mid], p) < 0) last = mid;
        else start = mid;
    }

    ll r0 = abs(areaTriangle(cv[0], cv[start], cv[last]));
    ll r1 = abs(areaTriangle(cv[0], cv[start], p));
    ll r2 = abs(areaTriangle(cv[0], cv[last], p));
    ll r3 = abs(areaTriangle(cv[start], cv[last], p));

    return (r0 == (r1 + r2 + r3));
}


int main(){
    fastio;
    ll L;
    cin >> L;
    fr(i,L){
        ll x, y;
        cin >> x >> y;
        large.pb(point{x,y});
    }
    ll S;
    cin >> S;
    fr(i,S){
        ll x, y;
        cin >> x >> y;
        small.pb(point{x,y});
    }

    auto cv = convexHull(large);

    ll ans = 0;
    for (auto p: small) 
        if (inPolygon(cv, p)) ans++;
    
    p(ans);
}