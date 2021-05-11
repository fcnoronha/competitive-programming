// MISCELANEUS STUFF OF GEOMETRY

// cool repos:
// https://github.com/mhunicken/icpc-team-notebook-el-vasito/tree/master/geometry
// https://github.com/LoppA/RepGod/tree/master/math/geometry
// https://github.com/mhunicken/icpc-team-notebook-el-vasito/tree/master/geometry

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

// counter-clockwise test 
int is_left(point a, point b, point c) {
    int det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // c is to the left
    if (det < 0) return -1; // c is to the right
    return 0;               // c is collinear
}

// comparator for radial sorting. Clockwise in comparisson with the center 
bool radial_cmp(point a, point b) {
    if (a.x - center.x >= 0 && b.x - center.x < 0) return true;
    if (a.x - center.x < 0 && b.x - center.x >= 0) return false;
    return (is_left(center, a, b) == 1);
}

// to be a retangle we have to have distances of the form 2a, 2b and 2c
bool is_retangle(Point a, Point b, Point c, Point d) {

    map<int, int> mp;
    mp[dist(a,b)] += 1;
    mp[dist(a,c)] += 1;
    mp[dist(a,d)] += 1;
    mp[dist(b,c)] += 1;
    mp[dist(b,d)] += 1;
    mp[dist(c,d)] += 1;

    for (auto x: mp) 
        if (x.s != 2)
            return false;

    return true;
}

// to be a square we have to have distances of the form 4a and 2b
bool is_square(Point a, Point b, Point c, Point d) {

    map<int, int> mp;
    mp[dist(a,b)] += 1;
    mp[dist(a,c)] += 1;
    mp[dist(a,d)] += 1;
    mp[dist(b,c)] += 1;
    mp[dist(b,d)] += 1;
    mp[dist(c,d)] += 1;

    bool two = 0, four = 0;
    for (auto x: mp) {
        if (x.s == 2) two = 1;
        if (x.s == 4) four = 1;
    }

    return two && four;
}

// Get area of a nondegenerate triangle, with sides a, b, c
double getAreaTriangle (double a, double b, double c) {
	double p = (a + b + c)/2.0;
	return sqrt (p * (p - a) * (p - b) * (p - c));
}