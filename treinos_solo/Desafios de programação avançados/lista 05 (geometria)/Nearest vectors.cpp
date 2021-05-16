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

typedef __int128_t ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const double EPS = 0.0000000001;

template <class T>
class Point {
public:    

    T x, y;

    Point () { }

    Point (T _x, T _y) : x(_x), y(_y) {}

    bool operator == (const Point &b) const {
        return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
    }

    bool operator < (const Point &b) const {
        return ((x < b.x) or ((x == b.x) and y < b.y));
    }

    bool operator > (const Point &b) const {
        return ((x > b.x) or ((x == b.x) and y > b.y));
    }

    // produto vetorial:
    // - p^q = |p|*|q|*sin(ang)	ang: directed ang from p to q(-PI < ang <= PI)
    // - p^q = 0 => ang = 0 or PI, p and q are colinear
    // - p^q > 0 => 0 < ang < PI / p^q < 0 => -PI < ang < 0
    // - p^q = directed area of paralelogram formed by vectors p and q
    // - dist point p to line ab = ||ab^p|| / ||ab||
    T operator ^ (const Point &b) const {
        return (this->x * b.y) - (this->y * b.x); 
    }

    // produto escalar:
    // - p*q = |p|*|q|*cos(ang)	ang: inner ang (0 <= ang < PI)
    // - p*q = 0 => ang = 90 / p*q > 0 => ang < 90 / p*q < 0 => ang > 90
    // - p*p = |p|^2  => |p| = sqrt(p*p)
    T operator * (const Point &b) const {
        return (this->x * b.x) + (this->y * b.y);
    }

    Point operator * (T k) const {
        return Point (x*k, y*k);
    }

    Point operator / (T k) const {
        return Point (x/k, y/k);
    }
    
    Point operator + (const Point &b) const {
        return Point (x + b.x, y + b.y);
    }

    Point operator - (const Point &b) const {
        return Point (x - b.x, y - b.y);
    }

    T len2 () const {
        return x*x + y*y;
    }

    ld len () const {
        return sqrt (x*x + y*y);
    }

    // distance point-point
    T dpp2 (const Point &b) const {
        return ((*this)-b)*((*this)-b);
    }

    T dpp (const Point &b) const {
        return ((*this)-b).len();
    }

    // oriented relative length of projection of this over b
    ld relative_proj (Point &b) const {
        return ((*this)*b)/(b.len()*b.len());
    }

    Point norm () const {
        return Point (x/this->len(), y/this->len());
    }
};

bool radial_cmp(Point<ll> a, Point<ll> b)
{
    if (a.x >= 0 && b.x < 0) return true;
    if (a.x < 0 && b.x >= 0) return false;
    if (a.x == 0 && b.x == 0) {
        if (a.y >= 0 || b.y >= 0) return a.y > b.y;
        return b.y > a.y;
    }

    ll det = (a.x*b.y) - (b.x*a.y);
    if (det < 0) return true;
    if (det > 0) return false;

    ll d1 = (a.x*a.x) + (a.y*a.y);
    ll d2 = (b.x*b.x) + (b.y*b.y);
    return d1 > d2;
}

int main() {
    //freopen("input.tft", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n; cin >> n;

    map<Point<ll>, int> rmp;
    Point<ll> v[n];
    fr(i, n) {
        long long int x, y; cin >> x >> y;
        v[i].x = x; 
        v[i].y = y;
        rmp[v[i]] = i+1;
    }

    sort(v, v+n, radial_cmp);

    pll bst = {-LINF, 1};
    ll bsta=0, bstb=0;
    fr(i, n) {
        int j = (i+1)%n;

        // Lei dos Cossenos: a**2 = b**2 + c**2 - 2*b*c*cos(A)

        ll a = v[i].dpp2(v[j]);
        ll b = Point<ll>(0,0).dpp2(v[i]);
        ll c = Point<ll>(0,0).dpp2(v[j]);

        ll num = (b+c-a)*(b+c-a); if ((b+c-a) < 0) num = -num;
        ll den = 4ll*b*c;

        // cout << "point:  " << v[i].x << " " << v[i].y << endl;
        // dbg((b+c-a));
        // ld ang = ld(sqrt(num)) / ld(sqrt(den));
        // dbg(acos(ang)*180.0/acos(-1));

        if (bsta==bstb || num*bst.s > bst.f*den) {
            bst = {num, den};
            bsta = i;
            bstb = j;
        }
    }

    cout << rmp[v[bsta]] << ' ' << rmp[v[bstb]] << endl;
}