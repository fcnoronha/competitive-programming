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

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// inner product
double inner(point p1, point p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

// cross product
double cross(point p1, point p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

// counter-clocwise test
bool ccw(point p, point q, point r) {
    return cross(q-p, r-p) > 0;
}

// three points are collinear
bool collinear(point p, point q, point r) {
    return fabs(cross(p-q, r-p)) < EPS;
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

    int n;
    cin >> n;

    polygon bisc;
    fr(i, n) {
        double x, y;
        cin >> x >> y;
        bisc.pb(point(x,y));
    }

    bisc = convexHull(bisc);
    n = (int)bisc.size();

    double ans = 10000000000000.0;
    fr(i, n) {

        double a = (bisc[i].y - bisc[(i+1)%n].y);
        double b = (bisc[(i+1)%n].x - bisc[i].x);
        double c = (bisc[i].x * bisc[(i+1)%n].y) - (bisc[(i+1)%n].x*bisc[i].y);

        double aux = 0.0;

        fr(j, n) {
            if (j == i || j == (i+1)%n) continue;

            double dist = abs( a*bisc[j].x + b*bisc[j].y + c );
            dist /= sqrt(a*a + b*b);
            aux = max(aux, dist);
        }
        
        if (aux < EPS || aux >= 1e9) continue; 
        ans = min(ans, aux);
    }

    cout << fixed << setprecision(7) << ans << endl;
}
