//codeforces.com/contest/993/problem/A

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
#define EPS 1e-9

using namespace std;


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


typedef vector<point> polygon;

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

polygon make_polygon(vector<point> P) {
	if (signedArea(P) < 0.0) reverse(P.begin(), P.end());
	int li = leftmostIndex(P);
	rotate(P.begin(), P.begin()+li, P.end());
	return P;
}

double perimeter(polygon & P) {
	double result = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) result += dist(P[i], P[(i+1)%n]);
	return result;
}

double area(polygon &P) {
	return fabs(signedArea(P));
}

bool isConvex(polygon & P) {
	int n = (int)P.size();
	if (n < 3) return false;
	bool left = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < n; i++) {
		if (ccw(P[i], P[(i+1)%n], P[(i+2)%n]) != left)
			return false;
	}
	return true;
}

bool inPolygon(polygon & P, point p) {
	if (P.size() == 0u) return false;
	double sum = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		if (P[i] == p || between(P[i], p, P[(i+1)%n])) return true;
		if (ccw(p, P[i], P[(i+1)%n])) sum += angle(P[i], p, P[(i+1)%n]);
		else sum -= angle(P[i], p, P[(i+1)%n]);
	}
	return fabs(fabs(sum) - 2*acos(-1.0)) < EPS;
}

polygon cutPolygon(polygon &P, point a, point b) {
	vector<point> R;
	double left1, left2;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		left1 = cross(b-a, P[i]-a);
		left2 = cross(b-a, P[(i+1)%n]-a);
		if (left1 > -EPS) R.push_back(P[i]);
		if (left1 * left2 < -EPS)
			R.push_back(lineIntersectSeg(P[i], P[(i+1)%n], a, b));
	}
	return make_polygon(R);
}

/*
 * Polygon Intersection
 */

point pivot(0, 0);

bool angleCmp(point a, point b) {
	if (collinear(pivot, a, b))
		return inner(pivot-a, pivot-a) < inner(pivot-b, pivot-b);
	return cross(a-pivot, b-pivot) >= 0;
}

#include <set>
bool intersect(polygon & A, polygon & B) {
	polygon P;
	int n = A.size(), m = B.size();
	for (int i = 0; i < n; i++) {
		if (inPolygon(B, A[i])) P.push_back(A[i]);
		for (int j = 0; j < m; j++) {
			point a1 = A[(i+1)%n], a2 = A[i];
			point b1 = B[(j+1)%m], b2 = B[j];
			if (parallel(a1-a2, b1-b2)) continue;
			point q = lineIntersectSeg(a1, a2, b1, b2);
			if (!between(a1, q, a2)) continue;
			if (!between(b1, q, b2)) continue;
			P.push_back(q);
		}
	}
	for (int i = 0; i < m; i++){
		if (inPolygon(A, B[i])) P.push_back(B[i]);
	}
	set<point> inuse; //Remove duplicates
	int sz = 0;
	for (int i = 0; i < (int)P.size(); ++i){
		if (inuse.count(P[i])) continue;
		inuse.insert(P[i]);
		P[sz++] = P[i];
	}
	P.resize(sz);
	return (!P.empty());

}

int main(){
    fastio

    polygon p1, p2;
    double x, y;
    fr(i, 4) {
        cin >> x >> y;
        p1.pb(point(x, y));
    }

    fr(i, 4) {
        cin >> x >> y;
        p2.pb(point(x, y));
    }

    if (intersect(p1, p2)) p("YES");
    else p("NO");
}
