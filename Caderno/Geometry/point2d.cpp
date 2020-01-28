using namespace std;
#define EPS 1e-9

// Point 2D

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    // return the norm of the point
    double norm() {
        return hypot(x, y);
    }
    // return the point normalized
    point normalized() {
        return point(x,y)*(1.0/norm());
    }
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

// distance between two points
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

point rotate(point p, double rad) {
    return point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}

// angle AÔB
double angle(point a, point o, point b) {
    return acos(inner(a-o, b-o) / (dist(o,a)*dist(o,b)));
}

// projection
point proj(point u, point v) {
    return v*(inner(u,v)/inner(v,v));
}

// if a point lies between two points
bool between(point p, point q, point r) {
    return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}

// intersection point of line PQ and AB
point lineIntersectSeg(point p, point q, point A, point B) {
    double c = cross(A-B, p-q);
    double a = cross(A, B);
    double b = cross(p, q);
    return ((p-q)*(a/c)) - ((A-B)*(b/c));
}

bool parallel(point a, point b) {
    return fabs(cross(a, b)) < EPS;
}

bool segIntersects(point a, point b, point p, point q) {
    if (parallel(a-b, p-q)) {
        return between(a, p, b) || between(a, q, b)
            || between(p, a, q) || between(p, b, q);
    }
    point i = lineIntersectSeg(a, b, p, q);
    return between(a, i, b) && between(p, i, q);
}

point closestToLineSegment(point p, point a, point b) {
    double u = inner(p-a, b-a) / inner(b-a, b-a);
    if (u < 0.0) return a;
    if (u > 1.0) return b;
    return a + ((b-a)*u);
}

// distance of point p to a-b
double distPointLine(point p, point a, point b) {
   
    // ax + by + c = 0
    double ac = (a.y - b.y);
    double bc = (b.x - a.x);
    double cc = (a.x * b.y) - (b.x*a.y);

    double dist = abs( ac*p.x + bc*p.y + cc);
    dist /= sqrt(ac*ac + bc*bc);
    
    return dist;
}

//works for int coordinates
bool polarCmp(point a, point b) {
    if (b.y*a.y > 0) return cross(a, b) > 0;
    else if (b.y == 0 && b.x > 0) return false;
    else if (a.y == 0 && a.x > 0) return true;
    else return b.y < a.y;
}

bool isRetangle(point p, point q, point r, point s) {

    // retangle of the form p ---- q
    //                      |      |
    //                      r ---- s

    return (fabs((q-p)*(r-p)) < EPS && fabs((q-s)*(r-s)) < EPS);
}

bool isSquare(point p, point q, point r, point s) {

    // square of the form p - q
    //                    |   |
    //                    r - s

    double d1 = dist(p, q);
    double d2 = dist(p, r);
    double d3 = dist(s, q);
    double d4 = dist(s, r);

    return (fabs(d1 - d2) < EPS && fabs(d1-d3) < EPS &&
            fabs(d1 - d3) < EPS);
}
