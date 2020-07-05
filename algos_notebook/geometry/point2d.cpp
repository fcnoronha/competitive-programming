using namespace std;
#define EPS 1e-9

// Point 2D

typedef pair<int, int> point;

// distance between two points
double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// inner/dot product
double inner(point p1, point p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

// cross/vectorial product
double cross(point p1, point p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

// angle AÔB, in radians
double angle(point a, point o, point b) {
    return acos(inner(a-o, b-o) / (dist(o,a)*dist(o,b)));
}

// rotate plane point is in
point rotate(point p, double rad) {
    return point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
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

