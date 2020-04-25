using namespace std;
#define EPS 1e-9

// Point 2D

typedef pair<long long int, long long int> point;

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

// works for int coordinates
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
