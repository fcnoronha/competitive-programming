#include <bits/stdc++.h>
using namespace std;

#define mk make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int, int> ii;
typedef long long ll;
const double EPS = 1e-9;
const double PI = acos(-1.0);

/* 
 *     /|
 *    /A|
 *  c/  |b  
 *  /   |
 * /B__C|
 *   a
 * Lei dos Cossenos: a**2 = b**2 + c**2 - 2*b*c*cos(A)
 * Lei dos Senos: a/sin(A) = b/sin(B) = c/sin(C)
 *
 * */

template <class T>
class Point {
public:    

    T x, y;

    Point () { }

    Point (T x, T y) : x(x), y(y) {}

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

    T len () const {
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
    double relative_proj (Point &b) const {
        return ((*this)*b)/(b.len()*b.len());
    }

    Point norm () const {
        return Point (x/this->len(), y/this->len());
    }

    // distance of point (p) from the segment (a-b)
    // return closest point (c) of the segment as reference
    double distToSegment (const Point a, const Point b, Point &c) const {
        // formula: c = a + u * ab
        Point p = *this;
        if (a == b) return p.dpp(a);
        Point ap = Point(p - a), ab = Point(b - a);
        double u = ap.relative_proj(ab);
        if (u < 0.0) u = 0.0;
        if (u > 1.0) u = 1.0;
        c = a + ab * u;
        return p.dpp(c);
    }

    Point rotate (T ang) const {
        T c = cos(ang), s = sin(ang);
        T X = x*c - y*s;
        T Y = x*s + y*c;
        return Point(X,Y);
    }

    // area of a convex or concave polygon, given a conter or
    // clockwise sorted vector of points
    static double area (vector <Point> v) {
        double area = 0.0;
        for (int i = 0; i < (int)v.size(); i++) 
            area += v[i] ^ v[(i+1)%v.size()];
        return abs(area/2.0);
    }

    T norm(T x) {
        if (x > 0) return 1;
        if (x < 0) return -1;
        return 0;
    }

    T sig_mul(T a, T b) {
        a = norm(a);
        b = norm(b);
        return a*b;
    }


    // Check if segment (ab) intersects with (cd), considera endpoints como dentro
    static bool inter (const Point &a, const Point &b, const Point &c, const Point &d) {
        Point ab = b-a;
        Point ac = c-a;
        Point ad = d-a;

        Point cd = d-c;
        Point ca = a-c;
        Point cb = b-c;

        // a, b, c, d -> Colineares
        // Se estiver desconsiderando endpoints nao precisa, essa parte +- testada
        if(abs(ab^ac) < EPS and abs(ab^ad) < EPS) {
            Point bc = c-b;
            Point bd = d-b;
            Point da = a-d;
            Point db = b-d;
            if((ac*ad) <= (T)0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((bc*bd) <= (T)0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((ca*cb) <= (T)0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((da*db) <= (T)0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            return false;
        }

        // >= para desconsiderar endpoints
        if(sig_mul(ab^ac, ab^ad) > (T)0)
            return false;

        // >= para desconsiderar endpoints
        if(sig_mul(cd^ca, cd^cb) > (T)0)
            return false;

        return true;
    }

    // distance of 2 farthest points. O(n) + O(convex_hull)
    // Rotating Calipers
    static double max_dist (vector <Point> p) {
        double ret = 0;
        p = Point::convex_hull(p);

        int n = p.size();
        if (n <= 1)
            return 0;
        if (n == 2)
            return p[0].dpp(p[1]);

        int at = 1;
        for (int i = 0; i < n; i++) {
            int j = (i + 1)%n;

            Point v = p[j] - p[i];
            int nxt = (at + 1)%n;
            while (nxt != i and (v^(p[nxt]-p[i])) >= (v^(p[at]-p[i]))) {
                at = nxt;
                nxt = (at + 1)%n;
            }

            ret = max (ret, max (p[i].dpp(p[at]), p[j].dpp(p[at])));
        }

        return ret;
    }
};