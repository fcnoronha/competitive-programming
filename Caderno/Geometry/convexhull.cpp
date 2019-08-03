#include <bits/stdc++.h>
#define EPS 1e-5
using namespace std;

// Convex Hull
// Uses 2D point and 2D polygon

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

/*
 * Codeforces 101657C
 */

point proj(point u, point v) {
	return v*(inner(u, v)/inner(v, v));
}

#define FOR(x,n) for(int x=0; (x)<(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=(n); (x)++)
#define INF 1e+55

int main() {
	int T;
	scanf("%d", &T);
	FOR1(caseNo, T) {
		int N;
		scanf("%d", &N);
		vector<point> arr(N);
		FOR(i, N) {
			scanf("%lf %lf", &arr[i].x, &arr[i].y);
		}
		polygon ch = convexHull(arr);
		vector<double> h(ch.size());
		int sz = ch.size();
		FOR(i, sz) {
			h[i] = 0;
			point v = ch[(i+1)%sz] - ch[i];
			for(point& p : ch) {
				point dp = p - ch[i];
				point d = dp - proj(dp, v);
				h[i] = max(h[i], d.norm());
			}
		}
		double ans = INF;
		FOR(i, sz) {
			FOR(j, sz) {
				if (i == j) continue;
				point v1 = ch[(i+1)%sz] - ch[i];
				point v2 = ch[(j+1)%sz] - ch[j];
				double sintheta = fabs(cross(v1, v2) / (v1.norm()*v2.norm()));
				if (fabs(sintheta) < EPS) continue;
				ans = min(ans, h[i]*h[j]/sintheta);
			}
		}
		printf("Swarm %d Parallelogram Area: %.4f\n", caseNo, ans);
	}
	return 0;
}
