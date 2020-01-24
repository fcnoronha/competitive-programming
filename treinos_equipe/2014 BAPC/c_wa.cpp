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

#define EPS 1e-9

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    // return the norm of the point

    // angle of the vector produced by the point
    double angle() { return atan2(y, x); }

    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        else return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    point operator +(point other) const {
        return point(x + other.x, y + other.y);
    }
    point operator -(point other) const {
        return point(x - other.x, y - other.y);
    }
    point operator *(double k) const {
        return point(x*k, y*k);
    }
};

typedef vector<point> polygon;

double cross(point p1, point p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point lineIntersectSeg(point p, point q, point A, point B) {
    double c = cross(A-B, p-q);
    double a = cross(A, B);
    double b = cross(p, q);
    return ((p-q)*(a/c)) - ((A-B)*(b/c));
}

double signedArea(polygon &P) {
    double result = 0.0;
    int n = P.size();
    for (int i = 0; i < n; i++) {
        result += cross(P[i], P[(i+1)%n]);
    }
    return result / 2.0;
}

int leftmostIndex(vector<point> &P) {
    int ans = 0;
    for(int i=1; i<(int)P.size(); i++) {
        if (P[i] < P[ans]) ans = i;
    }
    return ans;
}

polygon make_polygon(vector<point> &P) {
    if (signedArea(P) < 0.0) reverse(P.begin(), P.end());
    int li = leftmostIndex(P);
    rotate(P.begin(), P.begin()+li, P.end());
    return P;
}

bool ccw(point p, point q, point r) {
    return cross(q-p, r-p) > 0;
}

double inner(point p1, point p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(p-q, r-p)) < EPS;
}

point pivot(0, 0);

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

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        polygon pt(n);
        fr(i, n) 
            cin >> pt[i].x >> pt[i].y;
        
        double ans = 0.0;

        pt = convexHull(pt);
        n = pt.size();
        
        // sqr
        int l = 0, r = 0;
        fr(i, n) 
            for (int j = i+1; j < n; j++)
                if (dist(pt[i], pt[j]) > dist(pt[l], pt[r]))
                    l = i, r = j;


        fr(i, n) {
            
            if (i == r || i == l) continue;
            
            vector<pair<int, point>> tri;
            tri.pb({l, pt[l]});
            tri.pb({r, pt[r]});
            tri.pb({i, pt[i]});
            sort(all(tri));

            polygon aux;
            for (auto x: tri) aux.pb(x.s);
            ans = max(ans, signedArea(aux));
            
            for (int j = i+1; j < n; j++) {
                if (j == l || j == r) continue; 

              
                vector<pair<int, point>> sqr;
                sqr.pb({l, pt[l]});
                sqr.pb({i, pt[i]});
                sqr.pb({r, pt[r]});
                sqr.pb({j, pt[j]});
                sort(all(sqr));

                polygon auxx;
                for (auto x: sqr) auxx.pb(x.s);
                ans = max(ans, signedArea(auxx));
            }
        }

        p(ans);
    }
}