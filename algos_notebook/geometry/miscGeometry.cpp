// MISCELANEUS STUFF OF GEOMETRY

// counter-clockwise test 
int is_left(point a, point b, point c) {
    int det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // c is to the left
    if (det < 0) return -1; // c is to the right
    return 0;               // c is collinear
}

// if pointz form a retangle
bool isRetangle(point p, point q, point r, point s) {
    // retangle of the form p ---- q
    //                      |      |
    //                      r ---- s
    return (fabs((q-p)*(r-p)) < EPS && fabs((q-s)*(r-s)) < EPS);
}

// if points form a square
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

// comparator for radial sorting. Clockwise in comparisson with the center 
bool radial_cmp(point a, point b) {
    if (a.x - center.x >= 0 && b.x - center.x < 0) return true;
    if (a.x - center.x < 0 && b.x - center.x >= 0) return false;
    return (is_left(center, a, b) == 1);
}