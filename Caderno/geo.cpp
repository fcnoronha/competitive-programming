// Ponto:
pair<int, int> ponto; // ponto.f = x e p.s = y

// Distancia euclidiana:
double eucDist(pii p1, pii p2) {
	return hypot(p1.f - p2.f, p1.s - p2.s); 
}

// Linha (ax + by + c = 0):
struct line { double a, b, c; };

// Ponto em linha (armazena no parametro):
void pointsToLine(pii p1, pii p2, line &l) {
	if (abs(p1.f - p2.f) < EPS) {
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.f;
	} 
	else {
		l.a = -(double)(p1.s - p2.s) / (p1.f - p2.f);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.f) - p1.s;
	} 
}

// Linhas paralelas:
bool areParallel(line l1, line l2) {
	return (abs(l1.a-l2.a) < EPS) && (abs(l1.b-l2.b) < EPS); 
}

// Linhas iguais:
bool areSame(line l1, line l2) {
	return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); 
}

// Se linhas intersectam-se (retorna bool e o ponto p)
bool areIntersect(line l1, line l2, pii &p) {
	if (areParallel(l1, l2)) return false;
		p.f = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) p.s = -(l1.a * p.f + l1.c);
	else
		p.s = -(l2.a * p.f + l2.c);
	return true;
}



// Vetor:
pii vetor; //vetor.f = x / vetor.s = y

// Pontos em vetor:
pii toVec(pii a, pii b) {
	return vec(b.f - a.f, b.s - a.s); 
}

// Multiplicaçao por escalar:
pii scale(pii v, double s) {
	return vec(v.f * s, v.s * s); 
}

// Translada ponto de acordo com vetor
point translate(pii p, pii v) {
	return point(p.f + v.f , p.s + v.s); 
}

// dot_product:
double dot(pii a, pii b) { 
	return (a.f * b.f + a.s * b.s); 
}

// Norma:
double norm_sq(pii v) { 
	return v.f * v.f + v.s * v.s; 
}

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(pii p, pii a, pii b, pii &c) {
	pii ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c); 
}

// Orientaçao de 3 pintos:
// 0 --> p, q and r are colinear
// >0 --> Clockwise
// <0 --> Counterclockwise
int orientation(pii p1, pii p2, pii p3){

    int val = (p2.s - p1.s) * (p3.f - p2.f) -
              (p2.f - p1.f) * (p3.s - p2.s);

 	return val;
}
// Duvidas, leia: https://www.geeksforgeeks.org/orientation-3-ordered-points/

// ponto e circ:
int insideCircle(pii p, pii c, int r) {
	int dx = p.f - c.f, dy = p.s - c.s;
	int Euc = dx * dx + dy* dy, rSq = r * r;
	return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; //inside/border/outside
} 

// Representaçao de poligonos:
vector<pii> P; // IMPORTANTE: sempre repetir primeiro ponto no final

// Perimetro poligono:
double perimeter(vector<pii> &P) {
	double result = 0.0;
	for (int i = 0; i < P.size()-1; i++)
		result += dist(P[i], P[i+1]);
	return result; 
}

// Area poligono:
double area(vector<pii> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < P.size()-1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0; 
}

// Checando poligono convexo:
bool isConvex(vector<pii> &P) {
	int sz = P.size();
	if (sz <= 3) return false;
	bool isLeft = orientation(P[0], P[1], P[2]);
	for (int i = 1; i < sz-1; i++)
		if (orientation(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
			return false;
	return true; 
}

// COnvex hull em jarvis (On^2):
void convexHull(pii points[], int n)
{
    if (n < 3) return; 
    vector<pii> hull;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].f < points[l].f)
            l = i;

    int p = l, q;
    do {
        hull.push_back(points[p]); 
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {           
           if (orientation(points[p], points[i], points[q]) < 0)
               q = i;
        } 
        p = q;
 
    } while (p != l); 
    // Now yout hull in the hull vector  
}



// Convex hull com Graham Scan 
// O(nlogn)
// Eu ainda nao codei esse metodo, entao so copiei

#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
 
struct Point
{
    int x, y;
};
 
// A globle point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
Point p0;
 
// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted ouput if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;
 
   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}