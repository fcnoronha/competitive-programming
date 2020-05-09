#include <bits/stdc++.h>
using namespace std;

int main() {
	double l, k, t1, t2, h;
	scanf("%lf %lf %lf %lf %lf", &l, &k, &t1, &t2, &h);
	if ((int)(l * 100.0) > (int)(h * 100.0)) {
		printf("%.10lf %.10lf\n", h, h);
		return 0;
	}
	double a = t1;
	double b = -h - (t1 + t2) * k;
	double c = l * k;
	double dlt = sqrt(b * b - 4.0 * a * c);
	double r1 = (-b + dlt) / (2.0 * a);
	if ((int)(l * 100.0) == (int)(h * 100.0)) {
		printf("%.10lf %.10lf\n", h, r1 * t1);
	} else {
		printf("%.10lf %.10lf\n", t1 * r1, t1 * r1);
	}
}